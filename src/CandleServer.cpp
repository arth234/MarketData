#include "httplib.h"
#include "nlohmann/json.hpp"
#include <vector>
#include "CandleServer.h"
#include <mutex>
#include <string>

using json = nlohmann::json;
std::vector<Candle> period;
std::mutex mtx;

void candleServer(int port)
{
  httplib::Server servidor;

  servidor.Post("/candle", [](const
  httplib::Request& requisicao, 
  httplib::Response& resposta)
  {
    Candle c;
    json b = json::parse(requisicao.body);
    std::cout << "Post recebido\n";

    c.symbol = b["symbol"].get<std::string>();
    c.open = b["open"].get<double>();
    c.high = b["high"].get<double>();
    c.low = b["low"].get<double>();
    c.close = b["close"].get<double>();

    std::cout << "candle recebido:" << c.symbol 
    << "," << c.open << "," << c.high << "," <<
    c.low << "," << c.close << std::endl;     
    {
      std::lock_guard<std::mutex> lock(mtx);
      period.push_back(c);
    }

    {
      std::lock_guard<std::mutex> lock(mtx);
      if(period.size() >= 100)
        period.clear();
    }
    
    resposta.set_content("ok", "text/plain");
  });
  
  servidor.listen("0.0.0.0",port);
}
