#pragma once
#include <string>

class Item {
private:
    std::string id_;
    std::string name_;

public:
    Item(const std::string& id, const std::string& name)
            : id_(id), name_(name) {}

    std::string GetName() const { return name_; }
    // ... otros métodos relevantes
};