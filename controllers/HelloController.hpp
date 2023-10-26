#pragma once
#include <cpprest/http_listener.h>
#include "Base/Controller.hpp"


using namespace web;
using namespace web::http;
using namespace web::http::experimental::listener;

// Hello Controller
class HelloController : public Controller {
public:
    void HandleGet(http_request message) override {
        message.reply(status_codes::OK, U("Hello from the server GET!"));
    }

    void HandlePost(http_request message) override {
        message.reply(status_codes::OK, U("Hello from the server from POST!"));
    }

    void HandlePut(http_request message) override {
        message.reply(status_codes::OK, U("Hello from the server from PUT!"));
    }

    void HandleDelete(http_request message) override {
        message.reply(status_codes::OK, U("Hello from the server from DELETE!"));
    }

};