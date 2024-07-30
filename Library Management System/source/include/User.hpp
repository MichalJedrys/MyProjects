#ifndef USER_HPP
#define USER_HPP

#include <string>

enum class UserRole {
    Admin, 
    Member 
};

class User {
public:
    /**
     * @brief Default constructor.
     */
    User() noexcept = default;

    /**
     * @brief Parameterized constructor.
     * 
     * @param id User ID
     * @param username User's name
     * @param password User's password
     * @param role User's role
     */
    User(int id, const std::string& username, const std::string& password, UserRole role) noexcept;

    /**
     * @brief Get user ID.
     */
    int getId();

    /**
     * @brief Get Username.
     */
    std::string getUsername();

    /**
     * @brief Get user role.
     */
    UserRole getRole();

    /**
     * @brief Set user ID.
     */
    void setId(int newId);

    /**
     * @brief Set username
     */
    void setUsername(const std::string& newUsername);

    /**
     * @brief Set password
     */
    void setPassword(const std::string& newPassword);

    /**
     * @brief Set role.
     */
    void setRole(UserRole newRole);

    /**
     * @brief Check password.
     */
    bool checkPassword(const std::string& inputPassword) const;

private:
    /**
     * @brief Unique ID of the user.
     */
    int id = -1;

    /**
     * @brief User's name.
     */
    std::string username = "";

    /**
     * @brief User's password.
     */
    std::string password = "";

    /**
     * @brief User's role.
     */
    UserRole role = UserRole::Member;
};

#endif // USER_HPP