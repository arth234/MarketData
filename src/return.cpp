#include "OpenDB.h" 
#include "INDEX.h"
#include "ConstConcepts.h" 
#include "return.h" 

#include <vector>

double Return(size_t pull)
{
  loadCandles();	

  Concepts i;

  for(size_t x = pull; x < period.size(); x++)
  {
    double data = i.Net(x);
    return data++;
  }
  
  return {};
}
