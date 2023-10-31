#pragma once
#include "domain/entities/item/Item.hpp"

class IItemRepository {
public:
    virtual Item GetItem() = 0;
    virtual ~IItemRepository() = default;
};