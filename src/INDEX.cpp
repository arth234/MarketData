
#include <iostream>
#include <vector>
#include <cstddef>
#include "OpenDB.h"
#include "INDEX.h"

size_t getIn(size_t i)
{       
  loadCandles();

  return period.size() - i;
}

