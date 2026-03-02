
#include <iostream>
#include <vector>
#include <cstddef>
#include "CandleServer.h"
#include "INDEX.h"
#include <mutex>

size_t getIn(size_t i)
{       
  std::lock_guard<std::mutex> lock(mtx);
  return period.size() - i;
}

