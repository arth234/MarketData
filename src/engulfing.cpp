#include <vector>
#include "OpenDB.h"
#include "INDEX.h"
#include "ConstConcepts.h"
#include "engulfing.h"

bool Engulfing()
{ 
  bool engulfingx;
  double xnet;
  bool ralli;

  auto period = loadCandles();
 
  Concepts i(period);

  engulfingx = i.Body(2) < i.Body(1);

  for(auto x = 3; x < 7; x++)
  {
    xnet += i.Net(x);
  }  
  
  ralli = xnet != 0; 

  if(ralli && engulfingx)
  {
     return true;
  }

  return false;
}
