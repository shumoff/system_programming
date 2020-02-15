//
// Created by shumoff on 15.02.2020.
//

#ifndef TASK_5_USER_ACCOUNT_H
#define TASK_5_USER_ACCOUNT_H

#include <string>

class UserAccount {
public:
    UserAccount(std::string name, size_t id) : name_(std::move(name)), id_(id) {}
    UserAccount(const UserAccount& other) = default;
    UserAccount(UserAccount&& other) noexcept : name_(std::move(other.name_)), id_(other.id_) {}

    UserAccount& operator=(const UserAccount& other) noexcept {
        if (this == &other)
            return *this;
        id_ = other.id_;
        name_ = other.name_;
        return *this;
    }

    UserAccount& operator=(UserAccount&& other) noexcept {
        if (this == &other)
            return *this;
        id_ = other.id_;
        name_ = std::move(other.name_);
        return *this;
    }

    bool operator<(const UserAccount& other) {
        return id_ < other.get_id();
    }

    bool operator==(const UserAccount& other) {
        return id_ == other.get_id();
    }

    bool operator>(const UserAccount& other) {
        return id_ > other.get_id();
    }

    size_t get_id() const { return id_; }
    std::string get_name() const { return name_; }

private:
    std::string name_;
    size_t id_;
};


template<class T>
struct hash;

template <>
struct hash<UserAccount> {
    size_t operator()(UserAccount const & user) const {
        return std::hash<std::string>()(user.get_name()) ^ std::hash<size_t>()(user.get_id());
    }
};

#endif //TASK_5_USER_ACCOUNT_H
