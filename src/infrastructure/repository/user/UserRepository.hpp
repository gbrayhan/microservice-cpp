#pragma once
#include "IUserRepository.hpp"
#include "domain/entities/user/User.hpp"

class UserRepository : public IUserRepository {
public:
    User GetUser() override {
        return User("1", "Alice");
    }
};