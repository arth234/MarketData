#include <iostream>
#include "CandleServer.h"
#include "ConstConcepts.h"
#include <chrono>
#include <thread>

using namespace std;

int main()
{
  thread t(candleServer, 5000);
  t.detach();

  std::cout << "Main iniciou\n";

  Concepts i;

  while(true)
  {
    double corpo = i.Body(0); 
    std::cout << "body:" << corpo << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
  }
}
