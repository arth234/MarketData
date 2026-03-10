#pragma once
#include <string>
#include <map>
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

namespace net
{

static int server_fd;

struct JSON
{
    std::map<std::string,std::string> data;

    std::string operator[](const std::string& key)
    {
        return data[key];
    }
};

static JSON json;

inline void parse_json(const std::string& body)
{
    json.data.clear();

    size_t i = 0;

    while(true)
    {
        size_t key_start = body.find("\"", i);
        if(key_start == std::string::npos) break;

        size_t key_end = body.find("\"", key_start + 1);
        std::string key = body.substr(key_start + 1, key_end - key_start - 1);

        size_t colon = body.find(":", key_end);
        size_t value_start = colon + 1;

        size_t value_end = body.find(",", value_start);
        if(value_end == std::string::npos)
            value_end = body.find("}", value_start);

        std::string value = body.substr(value_start, value_end - value_start);

        if(value.size() > 0 && value[0] == '"')
            value = value.substr(1, value.size() - 2);

        json.data[key] = value;

        i = value_end + 1;
    }
}

inline void start_server(int port)
{
    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = INADDR_ANY;

    bind(server_fd,(sockaddr*)&addr,sizeof(addr));
    listen(server_fd,10);

    std::cout<<"Server running on "<<port<<std::endl;
}

inline void wait_route(const std::string& path)
{
    while(true)
    {
        int client_fd = accept(server_fd,nullptr,nullptr);

        char buffer[8192];
        int len = read(client_fd,buffer,8192);

        std::string req(buffer,len);

        if(req.find(path)!=std::string::npos)
        {
            size_t pos=req.find("\r\n\r\n");

            if(pos!=std::string::npos)
            {
                std::string body=req.substr(pos+4);
                parse_json(body);
            }

            std::string response=
            "HTTP/1.1 200 OK\r\n"
            "Content-Length:2\r\n\r\nOK";

            send(client_fd,response.c_str(),response.size(),0);
            close(client_fd);

            return;
        }

        close(client_fd);
    }
}

}

#define PORT(p) net::start_server(p)
#define ROUTE(p) net::wait_route(p)
