#pragma once
#include "domain/entities/user/User.hpp"
#include "infrastructure/repository/user/IUserRepository.hpp"


class UserRepository : public IUserRepository {
public:
    User GetUser() override {
        return User("1", "Alice");
    }
};