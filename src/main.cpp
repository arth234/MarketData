#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include "ConstConcepts.h"
#include "CandleServer.h"

int main()
{
  std::thread t(candleServer, 5000); 

  t.detach();

  double volatilidade;
  Concepts i;

  size_t shift;
  std::cin >> shift;

  while(true)
  { 
    volatilidade = i.Volatility(shift);
    std::cout << "volatilidade:" << volatilidade
    << std::endl; 
  }
  return 0;
}
