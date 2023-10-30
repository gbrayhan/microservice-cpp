#pragma once
#include "domain/entities/user/User.hpp"
#include "infrastructure/repository/user/UserRepository.hpp"
#include <memory>

class UserDomainService {
private:
    std::unique_ptr<UserRepository> userRepo_;

public:
    // Constructor que acepta un std::unique_ptr<UserRepository>
    UserDomainService(std::unique_ptr<UserRepository> repo)
            : userRepo_(std::move(repo)) {}

    bool IsValidUser(const User& user) {
        return !user.GetName().empty();
    }
    // ... otros métodos relacionados con la lógica de negocio de los usuarios
};
