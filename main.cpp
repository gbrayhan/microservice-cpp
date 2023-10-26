#include "controllers/HelloController.hpp"
#include "controllers/GoodbyeController.hpp"
#include <cpprest/http_listener.h>

using namespace web;
using namespace web::http;
using namespace web::http::experimental::listener;

enum class Route {
    Hello,
    Bye,
    Unknown
};

class SimpleServer {
public:
    SimpleServer()
            : helloController_(new HelloController()),
              goodbyeController_(new GoodbyeController()) {}

    void Start(const utility::string_t& url);

private:
    Route ResolveRoute(const utility::string_t& path);
    void HandleRequest(http_request message);

    http_listener listener_;
    std::unique_ptr<HelloController> helloController_;
    std::unique_ptr<GoodbyeController> goodbyeController_;
};

void SimpleServer::Start(const utility::string_t& url) {
    listener_ = http_listener(url);
    listener_.support([this](http_request message) { HandleRequest(message); });
    listener_.open().wait();

    ucout << utility::string_t(U("Listening for requests at: ")) << url << std::endl;
}

Route SimpleServer::ResolveRoute(const utility::string_t& path) {
    if (path == U("/hello")) return Route::Hello;
    if (path == U("/bye")) return Route::Bye;
    return Route::Unknown;
}

void SimpleServer::HandleRequest(http_request message) {
    Route route = ResolveRoute(uri::decode(message.relative_uri().path()));

    auto method = message.method();
    if (route == Route::Hello) {
        if (method == methods::GET) helloController_->HandleGet(message);
        else if (method == methods::POST) helloController_->HandlePost(message);
        else if (method == methods::PUT) helloController_->HandlePut(message);
        else if (method == methods::DEL) helloController_->HandleDelete(message);
        else message.reply(status_codes::MethodNotAllowed);
    }
    else if (route == Route::Bye) {
        if (method == methods::GET) goodbyeController_->HandleGet(message);
        else if (method == methods::POST) goodbyeController_->HandlePost(message);
        else if (method == methods::PUT) goodbyeController_->HandlePut(message);
        else if (method == methods::DEL) goodbyeController_->HandleDelete(message);
        else message.reply(status_codes::MethodNotAllowed);
    }
    else {
        message.reply(status_codes::NotFound, U("Route not found"));
    }
}

int main() {
    SimpleServer server;
    server.Start(U("http://localhost:8060/"));

    getchar();
    return 0;
}
