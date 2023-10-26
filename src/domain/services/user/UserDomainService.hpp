#pragma once
#include "domain/entities/user/User.hpp"

class UserDomainService {
public:
    bool IsValidUser(const User& user) {
        return !user.GetName().empty();
    }
    // ... otros métodos relacionados con la lógica de negocio de los usuarios
};