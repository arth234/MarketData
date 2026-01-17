
#include <iostream>
#include "marketdata.h"
#include <vector>
#include "INDEX.h"

size_t getIn(size_t i)
{
  for(size_t x = 0 ; x < period.size() ; x ++)
  {
    if (x >= period.size())
    {
      throw std::out_of_range("Index out of range");
    }

    return x + i;  
   }
 
   return {};
}

