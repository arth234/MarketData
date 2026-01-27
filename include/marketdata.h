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
        size_t volumeTick;
        size_t volumeReal;
        size_t volumeTechnical;
};

extern std::vector <candle> period;

candle getData(const std::string& filename);

