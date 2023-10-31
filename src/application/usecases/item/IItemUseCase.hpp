
#pragma once
#include "domain/entities/item/Item.hpp"

class IItemUseCase {
public:
    virtual Item RetrieveValidItem() = 0;
};