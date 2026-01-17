#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "marketdata.h"

std::vector<candle> period;

candle  getData(const std::string& filename)
{
  std::ifstream data(filename);

  if(!data.is_open())
  {
    std::cerr <<  "Cant load the database:" << 
    filename << std::endl;
  }
  std::string line;

  while(std::getline(data, line))
  {
    candle c;
    std::string value;
 
    std::stringstream ss(line);
    char delimiter = ',';

    if(std::getline(ss, c.timestamp, delimiter));
    if(std::getline(ss, value, delimiter))
    c.open = std::stod(value);

    if(std::getline(ss, value, delimiter))
    c.high = std::stod(value);
 
    if(std::getline(ss, value, delimiter))
    c.low = std::stod(value);

    if(std::getline(ss, value, delimiter))
    c.close = std::stod(value);
  
    period.push_back(c);

    return c;
  }
  
  return {};
}
 
