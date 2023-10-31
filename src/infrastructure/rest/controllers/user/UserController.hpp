#pragma once
#include <cpprest/http_listener.h>
#include "../baseController/Controller.hpp"
#include "application/usecases/user/UserUseCase.hpp"
#include <memory>

using namespace web;
using namespace web::http;
using namespace web::http::experimental::listener;

// user Controller
class UserController : public Controller {
private:
    std::unique_ptr<UserUseCase> userUseCase_;

public:
    UserController(std::unique_ptr<UserUseCase> useCase)
            : userUseCase_(std::move(useCase)) {}

    void HandleGet(http_request message) override {
        // obtener algún usuario
        //auto user = userUseCase_->GetSomeUser();

        // crear un objeto JSON
        web::json::value jsonValue;
        jsonValue[U("message")] = web::json::value::string(U("Hola from get method"));
        jsonValue[U("user")] = web::json::value::string(U("some user"));

        // responder con el objeto JSON
        message.reply(status_codes::OK, jsonValue);
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
