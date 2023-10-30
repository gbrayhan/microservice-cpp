#pragma once
#include <cpprest/http_listener.h>
#include "../baseController/Controller.hpp"
#include "domain/services/item/ItemDomainService.hpp"
#include <memory>

using namespace web;
using namespace web::http;
using namespace web::http::experimental::listener;

// item Controller
class ItemController : public Controller {
private:
    std::unique_ptr<ItemDomainService> itemDomainService_;


public:
    ItemController(std::unique_ptr<ItemDomainService> itemService)
            : itemDomainService_(std::move(itemService)) {}

    void HandleGet(http_request message) override {
        message.reply(status_codes::OK, U("Goodbye from the server from GET!"));
    }

    void HandlePost(http_request message) override {
        message.reply(status_codes::OK, U("Goodbye from the server from POST!"));
    }

    void HandlePut(http_request message) override {
        message.reply(status_codes::OK, U("Goodbye from the server from PUT!"));
    }

    void HandleDelete(http_request message) override {
        message.reply(status_codes::OK, U("Goodbye from the server from DELETE!"));
    }

};