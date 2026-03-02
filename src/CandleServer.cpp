#include <crow.h>
#include <vector>
#include <string>
#include <iostream>
#include "CandleServer.h"

std::vector<Candle> period;
std::mutex mtx;

void candleServer(uint16_t Port)
{
    try
    {       
        crow::SimpleApp app;
        app.loglevel(crow::LogLevel::Warning); // opcional

        CROW_ROUTE(app, "/ohlc")
        .methods(crow::HTTPMethod::Post)
        ([&](const crow::request& req) {
            auto json = crow::json::load(req.body);
            if(!json)
                return crow::response(400, "Invalid JSON");

            Candle c;
            c.symbol = json["symbol"].s();
            c.open   = json["open"].d();
            c.high   = json["high"].d();
            c.low    = json["low"].d();
            c.close  = json["close"].d();

            {
                std::lock_guard<std::mutex> lock(mtx);
                period.push_back(c);
            }

     

            return crow::response(200, "OK");
        });

        CROW_ROUTE(app, "/count")
        ([&]() {
            std::lock_guard<std::mutex> lock(mtx);
            return crow::response(std::to_string(period.size()));
        });

        app.port(Port).multithreaded().run();
    }
    catch(const std::exception& e)
    {
        std::cerr << "Erro no servidor: " << e.what() << std::endl;
    }
}
