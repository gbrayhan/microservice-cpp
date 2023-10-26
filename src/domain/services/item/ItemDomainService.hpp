#pragma once
#include "domain/entities/item/Item.hpp"

class ItemDomainService {
public:
    bool IsValidItem(const Item& item) {
        return !item.GetName().empty();
    }
    // ... otros métodos relacionados con la lógica de negocio de los usuarios
};