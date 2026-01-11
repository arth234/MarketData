#ifndef MARKETDATA_H
#define MARKETDATA_H

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

candle getData(const std::string& filename);

#endif //MARKETDATA_H
