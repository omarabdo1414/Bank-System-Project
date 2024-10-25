#ifndef LOGIN_H
#define LOGIN_H

#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>        // C++17 and above
#include "nlohmann/json.hpp" // For handling JSON
#include "customer.h"
#include "bank.h"

using namespace std;
namespace fs = std::filesystem;
using json = nlohmann::json;



class Temp
{
private:
    std::string userName, email, password;
    std::string searchName, searchPass, searchEmail;
    std::fstream file;
    json usersData; // JSON object to handle user data

    // Paths to store data
    const std::string folderPath = "./Data";             // Folder path for user data
    const std::string filePath = "Data/Login_data.json"; // File path for storing JSON data

public:
    // Function declarations
    bool login();
    void signUp();
    void forget();
};

class UserInputHandler
{
private:
    std::string userName, email, password;

public:
    std::string getUserName()
    {
        std::cout << "Enter Youe Name: ";
        std::cin.ignore();
        std::getline(std::cin, userName);
        return userName;
    }
    std::string getEmail()
    {
        std::string email;
        while (true)
        {
            std::cout << "Enter Email: ";
            std::getline(std::cin, email);
            if (email.length() > 10 && email.substr(email.length() - 10) == "@gmail.com")
            {
                return email;
            }
            else
            {
                std::cout << "Invalid email. Please enter a valid email ending with @gmail.com.\n";
            }
        }
    }

    std::string getPassword()
    {
        std::string password;
        std::cout << "Enter Password: ";
        std::getline(std::cin, password);
        return password;
    }
};

class IUserRepository {
public:
    virtual void saveUser(const std::string& userName, const std::string& email, const std::string& password) = 0;
    virtual bool loadUsers(json& usersData) = 0;
    virtual ~IUserRepository() = default;
};

class JSONUserRepository : public IUserRepository {
private:
    const std::string folderPath = "./Data";
    const std::string filePath = "Data/Login_data.json";
    Customer * customer;
public:
    void saveUser(const std::string& userName, const std::string& email, const std::string& password) override {
        json usersData;
        // Load existing data
        loadUsers(usersData);
        std::string id, name;
        std::shared_ptr<BankAccount> accountType;
        id = customer->getId();
        accountType = customer->getAccount();
        // Add new user data to JSON
        json newUser = {
            {"Name", userName},
            {"Email", email},
            {"Password", password},
            {"Id", id},
        };
        usersData.emplace_back(newUser);

        // Write updated data to JSON file
        std::ofstream outFile(filePath);
        outFile << usersData.dump(4);
        outFile.close();
    }

    bool loadUsers(json& usersData) override {
        // Check if folder exists, create it if not
        if (!fs::exists(folderPath)) {
            fs::create_directory(folderPath);
        }
        
        // Load data from JSON file
        std::ifstream inFile(filePath);
        if (inFile.is_open()) {
            inFile >> usersData;
            inFile.close();
            return true;
        } else {
            std::cout << "Error opening the file.\n";
            return false;
        }
    }
};


class UserAuthentication {
private:
    IUserRepository* userRepository;
public:
    UserAuthentication(IUserRepository* repo) : userRepository(repo) {}

    bool login(const std::string& userName, const std::string& password) {
        json usersData;
        if (!userRepository->loadUsers(usersData)) {
            return false;
        }

        for (auto& user : usersData) {
            if (user["Name"] == userName && user["Password"] == password) {
                std::cout << "Login successful! User Name: " << user["Name"] << ", Email: " << user["Email"] << std::endl;
                return true;
            }
        }
        std::cout << "Invalid user name or password!\n";
        return false;
    }
};


class UserAccountRecovery {
private:
    IUserRepository* userRepository;
public:
    UserAccountRecovery(IUserRepository* repo) : userRepository(repo) {}

    void recoverPassword(const std::string& email) {
        json usersData;
        if (!userRepository->loadUsers(usersData)) {
            return;
        }

        for (auto& user : usersData) {
            if (user["Email"] == email) {
                std::cout << "Account found! User Name: " << user["Name"] << ", Password: " << user["Password"] << std::endl;
                return;
            }
        }
        std::cout << "Account not found!\n";
    }
};


#endif // LOGIN_H
