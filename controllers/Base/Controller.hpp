#pragma once
#include <cpprest/http_listener.h>

using namespace web;
using namespace web::http;
using namespace web::http::experimental::listener;

// Abstract Controller Class
class Controller {
public:
    virtual void HandleGet(http_request message) = 0;
    virtual void HandlePost(http_request message) = 0;
    virtual void HandlePut(http_request message) = 0;
    virtual void HandleDelete(http_request message) = 0;
};