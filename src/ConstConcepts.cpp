#include "Index.h"
#include "CandleServer.h"
#include "ConstConcepts.h"
#include <cmath>
#include <mutex>
#include <numeric>
#include <atomic>

Concepts::Concepts(){}

long double Concepts::Body(size_t i)
{
  std::atomic<size_t> j{0};
  size_t atual = j.load(std::memory_order_acquire);
  if(i >= atual)
    return 0.0;

  std::lock_guard<std::mutex> lock(mtx);
  Candle& c = period[(atual - 1 - i) % 1024];
  return std::abs(c.close - c.open);
}
long double Concepts::Net(size_t i)
{
  std::atomic<size_t> j{0};
  size_t atual = j.load(std::memory_order_acquire);
  if(i >= atual)
    return 0.0;

  std::lock_guard<std::mutex> lock(mtx);
  Candle& c = period[(atual - 1 - i) % 1024];    
  return c.close - c.open;
}

long double Concepts::UpperShadow(size_t i) 
{
  std::atomic<size_t> j{0};
  size_t atual = 
  j.load(std::memory_order_acquire);
  if(i >= atual)
    return 0.0;

  std::lock_guard<std::mutex> lock(mtx);
  double c = period[getIn(i)].high -
  std::max(period[getIn(i)].open,
  period[getIn(i)].close);
  
  return c;
}

long double Concepts::LowerShadow(size_t i) 
{ 
  std::atomic<size_t> j{0};
  size_t atual = j.load(std::memory_order_acquire);
  if(i >= atual)
    return 0.0;

  std::lock_guard<std::mutex> lock(mtx);
  double c = std::min(period[getIn(i)].open,
  period[getIn(i)].close) -
  period[getIn(i)].low;
  
  return c;
}

long double Concepts::Volatility(size_t i)
{
  std::atomic<size_t> j{0};
  std::lock_guard<std::mutex> lock(mtx);

  size_t N = 
  j.load(std::memory_order_acquire);
  if (N < i || i == 0)
    return 0.0;
    double sum = 0.0;

    // últimos i candles
  for (size_t count = 0; count < i; count++)
  {
    Candle& c = period[getIn(N - 1 - count)];
    double body = std::abs(c.close - c.open);
    sum += body;
  }

  double mean = sum / i;
  double sq_sum = 0.0;

  for (size_t count = 0; count < i; count++)
  {
    Candle& c = period[getIn(N - 1 - count)];
    double body = std::abs(c.close - c.open);
    sq_sum += (body - mean) * (body - mean);
  }

  return std::sqrt(sq_sum / i);
}

long double Concepts::Return(size_t i)
{
  std::atomic<size_t> j{0};
  std::lock_guard<std::mutex> lock(mtx);
  size_t tamanho = 
  j.load(std::memory_order_acquire);
  double data;

  if(tamanho <= i)
    return 0.0;

  for(size_t x = 0 - i; x < tamanho; x++)
  {
    data += std::abs(Net(x));
  }

  return data / i;
}
