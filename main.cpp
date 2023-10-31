#include "infrastructure/rest/controllers/user/UserController.hpp"
#include "infrastructure/rest/controllers/item/ItemController.hpp"
#include "domain/services/user/UserDomainService.hpp"
#include "domain/services/item/ItemDomainService.hpp"
#include "infrastructure/repository/user/UserRepository.hpp"
#include "infrastructure/repository/item/ItemRepository.hpp"
#include "application/usecases/user/UserUseCase.hpp"
#include "application/usecases/item/ItemUseCase.hpp"
#include <cpprest/http_listener.h>

using namespace web;
using namespace web::http;
using namespace web::http::experimental::listener;

enum class Route {
    Item,
    User,
    Unknown
};

class SimpleServer {
public:
    SimpleServer() {
        // Crear las dependencias y "inyectarlas"
        std::unique_ptr<UserRepository> userRepo(new UserRepository());
        UserDomainService userDomainService(std::move(userRepo));  // Mueve el repositorio al UserDomainService
        std::unique_ptr<UserUseCase> userUseCase(new UserUseCase(userDomainService, std::move(userRepo)));  // Pasa el UserDomainService al UserUseCase
        userController_ = std::unique_ptr<UserController>(new UserController(std::move(userUseCase)));


        std::unique_ptr<ItemRepository> itemRepo(new ItemRepository());
        ItemDomainService itemDomainService(std::move(itemRepo));  // Mueve el repositorio al ItemDomainService
        std::unique_ptr<ItemUseCase> itemUseCase(new ItemUseCase(itemDomainService, std::move(itemRepo)));  // Pasa el ItemDomainService al ItemUseCase
        itemController_ = std::unique_ptr<ItemController>(new ItemController(std::move(itemUseCase)));
    }
    void Start(const utility::string_t& url);

private:
    Route ResolveRoute(const utility::string_t& path);
    void HandleRequest(http_request message);

    http_listener listener_;
    std::unique_ptr<UserController> userController_;
    std::unique_ptr<ItemController> itemController_;
};

void SimpleServer::Start(const utility::string_t& url) {
    listener_ = http_listener(url);
    listener_.support([this](http_request message) { HandleRequest(message); });
    listener_.open().wait();

    ucout << utility::string_t(U("Listening for requests at: ")) << url << std::endl;
}

Route SimpleServer::ResolveRoute(const utility::string_t& path) {
    if (path == U("/user")) return Route::User;
    if (path == U("/item")) return Route::Item;
    return Route::Unknown;
}

void SimpleServer::HandleRequest(http_request message) {
    Route route = ResolveRoute(uri::decode(message.relative_uri().path()));

    auto method = message.method();
    if (route == Route::User) {
        if (method == methods::GET) userController_->HandleGet(message);
        else if (method == methods::POST) userController_->HandlePost(message);
        else if (method == methods::PUT) userController_->HandlePut(message);
        else if (method == methods::DEL) userController_->HandleDelete(message);
        else message.reply(status_codes::MethodNotAllowed);
    }
    else if (route == Route::Item) {
        if (method == methods::GET) itemController_->HandleGet(message);
        else if (method == methods::POST) itemController_->HandlePost(message);
        else if (method == methods::PUT) itemController_->HandlePut(message);
        else if (method == methods::DEL) itemController_->HandleDelete(message);
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
