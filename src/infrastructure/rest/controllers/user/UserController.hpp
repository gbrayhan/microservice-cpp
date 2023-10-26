#pragma once
#include <cpprest/http_listener.h>
#include "../baseController/Controller.hpp"


using namespace web;
using namespace web::http;
using namespace web::http::experimental::listener;

// user Controller
class UserController : public Controller {
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