#pragma once
#include <string>

class User {
private:
    std::string id_;
    std::string name_;

public:
    User(const std::string& id, const std::string& name)
            : id_(id), name_(name) {}

    std::string GetName() const { return name_; }
    // ... otros métodos relevantes
};