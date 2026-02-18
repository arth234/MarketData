#pragma once

#include <vector>
#include <cmath>
#include <algorithm> 
#include "OpenDB.h"

class Concepts {
public:
    // Construtor
    explicit Concepts();

    // Funções de cálculo
    double Body(size_t i);
    double Net(size_t i);
    double UpperShadow(size_t i);
    double LowerShadow(size_t i);
    double Volatility(size_t i);
};

