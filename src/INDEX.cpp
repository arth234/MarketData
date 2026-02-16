
#include <iostream>
#include <vector>
#include <cstddef>
#include "OpenDB.h"
#include "INDEX.h"

std::vector<Candle> period;

size_t getIn(size_t i)
{       
  return period.size() - i;
}

