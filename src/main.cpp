#include <iostream>
#include <curl/curl.h>
#include <string>

size_t WriteCallBack(void* contents, size_t size, size_t nmemb, void* userp)
{
    size_t totalSize = size * nmemb;

    std::string* output = static_cast<std::string*>(userp);
    output->append(static_cast<char*>(contents), totalSize);

    return totalSize;
}

int main()
{
  while(true)
 {
    CURL* web;
    CURLcode res;
    std::string response;
    web = curl_easy_init();
    if(!web) 
    {
      std::cerr << "Failed to init web!" << std::endl;
    
      return 1;
    }
    curl_easy_setopt(web, CURLOPT_URL,
    "https://api.binance.com/api/v3/ticker/price?symbol=BTCUSDT");

    curl_easy_setopt(web, CURLOPT_WRITEFUNCTION, WriteCallBack);
    curl_easy_setopt(web, CURLOPT_WRITEDATA, &response);
  
    res = curl_easy_perform(web);

    if(res != CURLE_OK)
    {
      std::cerr << "web with error:" << 
      curl_easy_strerror(res) << std::endl;
    }
    else
    {
      std::cout << response << std::endl;
    }
  
    curl_easy_cleanup(web);
  }

  return 0;
}
