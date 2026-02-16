#pragma once

#include <vector>
#include <cmath>
#include <algorithm> // para std::min e std::max
#include "OpenDB.h"  // certifique-se de ter o struct Candle definido aqui
#include "INDEX.h"

class Concepts {
private:
    std::vector<Candle>& period;

public:
    // Construtor
    explicit Concepts(std::vector<Candle>& c);

    // Funções de cálculo
    double Body(size_t i) const;
    double Net(size_t i) const;
    double UpperShadow(size_t i) const;
    double LowerShadow(size_t i) const;
};

