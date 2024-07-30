#include "User.hpp"

User::User(int id, const std::string& username, const std::string& password, UserRole role) noexcept
: id(id)
, username(username)
, password(password)
, role(role)
{
}

int User::getId() const {
    return id; 
}

std::string User::getUsername() const { 
    return username; 
}
UserRole User::getRole() const { 
    return role; 
}

void User::setId(
    int newId) { id = newId; 
}
void User::setUsername(const std::string& newUsername) { 
    username = newUsername; 
}
void User::setPassword(const std::string& newPassword) { 
    password = newPassword; 
}
void User::setRole(UserRole newRole) { 
    role = newRole; 
}

bool User::checkPassword(const std::string& inputPassword) const { 
    return password == inputPassword; 
}