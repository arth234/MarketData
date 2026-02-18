#pragma once
#include <vector>

struct Candle
{
    int time;
    double open;
    double high;
    double low;
    double close;
    long tick_volume;
    long real_volume;
    double technical_volume;
};

extern std::vector<Candle> period;

void loadCandles();

