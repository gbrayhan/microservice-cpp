#pragma once

#include "domain/entities/user/User.hpp"

class IUserRepository {
public:
    virtual User GetUser() = 0;
};