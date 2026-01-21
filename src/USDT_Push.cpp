#include <curl/curl.h>
#include <vector>
#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include "OHLC_Push.h"
#include "marketdata.h"

using namespace std;

double value[4];
size_t writecallback(void* contents,
size_t size, size_t nmemb, void* userp)
{
  size_t totalSize = size * nmemb;

  string* output = static_cast<string*>(userp); 

  output -> append = static_cast<char*>(contents),
  totalSize;

  return totalSize; 
}

struct timeframe
{
  string time;
  size_t periods;
};

timeframe x;

candle OHLC_push(const string& symbol, x.time, 
x.periods)
{
  candle c;

  CURL* data;
  CURLcode debug;

  string response;

  data = curl_easy_init();
  if(!data)
  {
    cerr << "ERROR TRYING TO PUSH DATA\n";
    return {};
  }

  curl_easy_setopt(data, CURLOPT_URL, 
  "https://api.binance.com/api/v3/ticker/price?symbol="
  + symbol);

  curl_easy_setopt(data, CURLOPT_WRITEFUNCTION,
  writecallback);
 
  curl_easy_setopt(data, CURL_WRITEDATA, &response);

  debug = curl_easy_perform(data);

  if(!debug == CURLE_OK)
  {
    cerr << "data with error" << debug << endl;
  }
  else
  {
    /*Data Pushing class action where that specific
    function will return the ohlc data from the
    real time market data from the binance encapsulating it*/

    this_thread::sleep_for(chrono::time(periods));
    period.push_back(c.open = response)
    
  }

  curl_easy_cleanup(data);
  
  return {};
}
