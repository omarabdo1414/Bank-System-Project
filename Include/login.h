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

#endif // LOGIN_H
