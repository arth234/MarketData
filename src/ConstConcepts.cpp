#include "Index.h"
#include "CandleServer.h"
#include "ConstConcepts.h"
#include <cmath>
#include <mutex>
#include <numeric>

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
  size_t N = period.size();
  if(N < 2) return 0.0;

  double sum = 0.0;
  for(size_t count = 0; count < i; count++)
  {
    sum += Body(i);
  }
  double mean = sum / i;
  double sq_sum = 0.0;

  for(size_t square = 0; square < i; ++square)
  {
    double b = Body(square);
    sq_sum += (b - mean) * (b - mean);
  }

  return std::sqrt(sq_sum / (i));
}

double Concepts::Return(size_t i)
{
  std::lock_guard<std::mutex> lock(mtx);
  double data;

  for(size_t x = period.size() - i; x < period.size(); x++)
  {
    data += Net(x);
  }

  return data / i;
}
