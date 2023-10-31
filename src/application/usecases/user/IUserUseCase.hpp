
#pragma once
#include "domain/entities/user/User.hpp"

class IUserUseCase {
public:
    virtual User RetrieveValidUser() = 0;
};