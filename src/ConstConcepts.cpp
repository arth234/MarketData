#include "INDEX.h"
#include "CandleServer.h"
#include "ConstConcepts.h"
#include <cmath>
#include <mutex>

Concepts::Concepts(){}

double Concepts::Body(size_t i)
{
  std::lock_guard<std::mutex> lock(mtx);
  if(period.empty() || i >= period.size())
    return 0;
  Candle& c = period[period.size() - 1 - i];
  return std::abs(c.close - c.open);
}

double Concepts::Net(size_t i)
{
  std::lock_guard<std::mutex> lock(mtx);
  if (i >= period.size()) return 0;
    return period[getIn(i)].close -
    period[getIn(i)].open;
}
double Concepts::UpperShadow(size_t i) 
{
  std::lock_guard<std::mutex> lock(mtx);
  if (i >= period.size()) return 0;
    return period[getIn(i)].high -
    std::max(period[getIn(i)].open,
    period[getIn(i)].close);
}
double Concepts::LowerShadow(size_t i) 
{ 
  std::lock_guard<std::mutex> lock(mtx);
  if (i >= period.size()) return 0;
    return std::min(period[getIn(i)].open,
    period[getIn(i)].close) -
    period[getIn(i)].low;
}
double Concepts::Volatility(size_t i)
{
  std::lock_guard<std::mutex> lock(mtx);
  double retorno;
  double retornoMedia;
  double retornoEx;
  double deviation;
  double square;
  if(i >= period.size()) return 0;
  for(size_t x = 0; x < i; x++)
  {
    retorno += std::abs(Net(x));
  }
  retornoMedia = retorno / i;  
  for(size_t x = 0; x < i; x++)
  {
    retornoEx = std::abs(Net(x));
    deviation = retornoEx - retornoMedia;    
    square += std::pow(deviation, 2);    
  }
  return std::sqrt(square / i);
}

