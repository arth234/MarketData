#include <curl/curl.h>
#include <string>
#include "get.h"

using namespace std;

static size_t writecallback(void* contents,
size_t size, size_t nmemb, void* userp)
{
  ((string*)userp)->append((char*)contents, size *
  nmemb));

    return size * nmemb;
}

string get(const string& url)
{
  CURL* curl = curl_easy_init();
  string response;
  
  if(curl)
  {
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, WRITEFUNCTION,
    writecallback);

    curl_easy_setopt(curl, CURLOPT_WRITEDATA,
    &response);

    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER,
    1L);

    curl_easy_perform(curl);

    curl_easy_cleanup(curl);
  }

  return response;
}
