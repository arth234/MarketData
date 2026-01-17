#pragma once

#include <string>
#include <vector>

struct candle
{
	std::string timestamp;
	double open;
	double high;
	double low;
	double close;
};

extern std::vector <candle> period;

candle getData(const std::string& filename);

