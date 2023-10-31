#pragma once
#include "application/usecases/item/IItemUseCase.hpp"
#include "infrastructure/repository/item/IItemRepository.hpp"
#include "domain/services/item/ItemDomainService.hpp"

class ItemUseCase : public IItemUseCase {
private:
    std::unique_ptr<IItemRepository> repository_;
    ItemDomainService& itemDomainService_;  // Cambiado a referencia

public:
    ItemUseCase(ItemDomainService& itemDomainService, std::unique_ptr<IItemRepository> repo)
            : itemDomainService_(itemDomainService), repository_(std::move(repo)) {}  // Ajustado el orden aquí

    Item RetrieveValidItem() {
        auto item = repository_->GetItem();
        // Suponiendo que ItemDomainService tiene un método IsValidItem
        if (itemDomainService_.IsValidItem(item)) {
            return item;
        }
        return Item("", "");  // Asumiendo que Item tiene un constructor similar a User
    }
};
