
#pragma once
#include "IUsecase.hpp"
#include "infrastructure/repository/user/IUserRepository.hpp"
#include "domain/services/user/UserService.hpp"

class UserUseCase : public IUserUseCase {
private:
    std::unique_ptr<IUserRepository> repository_;
    UserService userService_;

public:
    UsecaseImpl(std::unique_ptr<IUserRepository> repo)
            : repository_(std::move(repo)) {}

    User RetrieveValidUser() override {
        auto user = repository_->GetUser();
        if (userService_.IsValidUser(user)) {
            return user;
        }
        return User("", "");
    }
};