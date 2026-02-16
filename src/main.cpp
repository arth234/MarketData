#include <iostream>
#include <chrono>
#include <thread>
#include "ConstConcepts.h"
#include "OpenDB.h"
#include "INDEX.h"
#include "engulfing.h"

using namespace std;

int main()
{
  bool engulfing;
  size_t pttern;
  while(true)
  {
    engulfing = Engulfing();

    if(engulfing)
    {
      pttern ++;
    }
    Concepts c(period);

    cout << "engolfo =" << pttern << endl;
    cout << "body =" << c.Body(1) << endl;

    cout << period[getIn(1)].close << endl; 
  }

  return 0;
}

