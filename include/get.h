#pragma once

#include <string>

static size_t writecallback(void* contents,
size_t size, size_t nmemb, void* userp);

string get(const string& url);
