#ifndef REQUESTS_H
#define REQUESTS_H
#include <string>
#include <curl/curl.h>



class crl
{
    CURL *curl;
    CURLcode res;
    std::string readBuffer;
    static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp);
public:

    crl();

    std::string post(std::string url, std::string fields);


    std::string get(std::string url);
};


#endif // REQUESTS_H
