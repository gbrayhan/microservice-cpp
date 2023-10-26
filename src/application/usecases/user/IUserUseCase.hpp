
#pragma once
#include "domain/entities/User.hpp"

class IUseCaseUser {
public:
    virtual User RetrieveValidUser() = 0;
};