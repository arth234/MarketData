#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <string>
#include <atomic>
#include "ConstConcepts.h"
#include "CandleServer.h"

std::mutex mart;

int main(int argc, char *argv[])
{
  std::atomic<size_t> indice{0};
  int port = std::stol(argv[1]);
  
  std::thread t(candleServer, port, &indice); 
  t.detach();

  Concepts i;

  size_t a;
  size_t shift;
  std::cin >> shift;
  while(true)
  {
    size_t total = indice.load(std::memory_order_acquire); 
    if(total < shift)
    {
      std::this_thread::sleep_for(
      std::chrono::milliseconds(10));
      continue;
    }
 
    {
      std::lock_guard<std::mutex> lock(mart);
      for(size_t x = 0; x < total; x++)
      {
        double vol = i.Volatility(shift);
        double liquid = i.Net(total);
        double lucroLiqdo = i.Return(1);

        std::cout << vol << "|" << liquid << 
        "|" << lucroLiqdo << "|" << 
        total << "|" << period[total].close  << std::endl;

        if(vol == vol  && liquid < 0)
        {
          std::cout << " retorno de " << lucroLiqdo << 
          "|" << total << std::endl;
        }
      }
    }
    
    std::this_thread::sleep_for(
    std::chrono::milliseconds(6));
  } 

  return 0;
}
