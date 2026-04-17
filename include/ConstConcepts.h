#pragma once

#include <vector>
#include <cmath>
#include <algorithm> 
#include "CandleServer.h"

class Concepts {
public:
    // Construtor
  explicit Concepts();

    // Funções de cálculo
  long double Body(size_t i);
  long double Net(size_t i);
  long double UpperShadow(size_t i);
  long double LowerShadow(size_t i);
  long double Volatility(size_t i);
  long double Return(size_t i);   
};

