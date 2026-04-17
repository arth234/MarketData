#include "httplib.h"
#include "nlohmann/json.hpp"
#include "CandleServer.h"

#include <atomic>
#include <cstring>
#include <iostream>
#include <string>

using json = nlohmann::json;

Candle period[1024];
std::mutex mtx;

void candleServer(int port, std::atomic<size_t>* indice)
{
    httplib::Server servidor;

    servidor.Post("/candle",
    [indice](const httplib::Request& requisicao,
       httplib::Response& resposta)
    {
        Candle c;

        json b = json::parse(requisicao.body);

        std::string sym = b["symbol"];

        strncpy(c.symbol, sym.c_str(), sizeof(c.symbol) - 1);
        c.symbol[sizeof(c.symbol) - 1] = '\0';

        c.open  = b["open"];
        c.high  = b["high"];
        c.low   = b["low"];
        c.close = b["close"];

        size_t i =
            indice->fetch_add(1, std::memory_order_relaxed) & 1023;

        period[i] = c;

        resposta.set_content("ok", "text/plain");
    });

    servidor.listen("0.0.0.0", port);
}
