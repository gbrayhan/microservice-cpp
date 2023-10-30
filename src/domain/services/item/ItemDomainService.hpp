#pragma once
#include "domain/entities/item/Item.hpp"
#include "infrastructure/repository/item/ItemRepository.hpp"
#include <memory>

class ItemDomainService {
private:
    std::unique_ptr<ItemRepository> itemRepo_;

public:
    // Constructor que acepta un std::unique_ptr<ItemRepository>
    ItemDomainService(std::unique_ptr<ItemRepository> repo)
            : itemRepo_(std::move(repo)) {}

    bool IsValidItem(const Item& item) {
        return !item.GetName().empty();
    }
    // ... otros métodos relacionados con la lógica de negocio de los ítems
};
