
#include <iostream>
#include <vector>
#include <cstddef>
#include "CandleServer.h"
#include "Index.h"
#include <mutex>

size_t getIn(size_t i)
{       
  return period.size() - 1 - i;
}

