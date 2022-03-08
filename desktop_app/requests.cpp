
#include "requests.h"


size_t crl::WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

crl::crl()
{
}

std::string  crl::post(std::string url, std::string fields)
{
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, fields.c_str());

    res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);

    return readBuffer;
}


std::string  crl::get(std::string url)
{
        curl = curl_easy_init();
        if(!curl)
            throw "curl does not work";

        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        return readBuffer;
    }

