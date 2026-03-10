#include "socket.h"
#include <vector>
#include "CandleServer.h"
#include <mutex>

using namespace net;

std::vector<Candle> period;
std::mutex mtx;

void candleServer(int port)
{
  Candle c;

  PORT(port);
  ROUTE("/ohlc");

  c.symbol = json["symbol"];
  c.open   = std::stod(json["open"]);
  c.high   = std::stod(json["high"]);
  c.low    = std::stod(json["low"]);
  c.close  = std::stod(json["close"]); 

  {
    std::lock_guard<std::mutex> lock(mtx);
    period.push_back(c);
  }
}
