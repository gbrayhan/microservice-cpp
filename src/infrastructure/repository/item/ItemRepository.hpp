#pragma once
#include "infrastructure/repository/item/IItemRepository.hpp"
#include "domain/entities/item/Item.hpp"

class ItemRepository : public IItemRepository {
public:
    Item GetItem() override {
        return Item("1", "Alice");
    }
};