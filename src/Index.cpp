#include <iostream>
#include <vector>
#include <cstddef>
#include <mutex>
#include <atomic>

#include "CandleServer.h"
#include "Index.h"

std::atomic<size_t>indice{0};

size_t getIn(size_t i)
{ 
  size_t tamanhoAt = indice.load(std::memory_order_acquire);
   return i;
}

