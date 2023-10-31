#pragma once
#include "application/usecases/user/IUserUseCase.hpp"
#include "infrastructure/repository/user/IUserRepository.hpp"
#include "domain/services/user/UserDomainService.hpp"

class UserUseCase : public IUserUseCase {
private:
    std::unique_ptr<IUserRepository> repository_;
    UserDomainService& userDomainService_;  // Cambiado a referencia

public:
    UserUseCase(UserDomainService& userDomainService, std::unique_ptr<IUserRepository> repo)
            : userDomainService_(userDomainService), repository_(std::move(repo)) {}  // Ajustado el orden aquí

    User RetrieveValidUser() override {
        auto user = repository_->GetUser();
        if (userDomainService_.IsValidUser(user)) {
            return user;
        }
        return User("", "");
    }

    User GetSomeUser()  {
        return repository_->GetUser();
    }
};
