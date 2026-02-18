#include <vector>
#include "engulfing.h"
#include "OpenDB.h"
#include "INDEX.h"
#include "ConstConcepts.h"

bool RisingEngulfing(size_t push)
{ 
  bool engulfingx;
  double xnet;
  bool ralli;
 
  Concepts i;

  loadCandles();

  engulfingx = i.Body(2 + push) < i.Body(1 + push);

  for(auto x = 3 + push; x < (7 + push); x++)
  {
    xnet += i.Net(x);
  }  
  
  ralli = xnet < 0; 

  if(ralli && engulfingx)
  {
     return true;
  }

  return false;
}

bool DownEngulfing(size_t push)
{ 
  bool engulfingx;
  double xnet;
  bool ralli;
 
  Concepts i;

  loadCandles();

  engulfingx = i.Body(2 + push) < i.Body(1 + push);

  for(auto x = 3 + push; x < (7 + push); x++)
  {
    xnet += i.Net(x);
  }  
  
  ralli = xnet > 0; 

  if(ralli && engulfingx)
  {
     return true;
  }

  return false;
}
