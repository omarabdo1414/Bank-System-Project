#include "./login.h"

void Temp::signUp() {
    std::cout << "\nEnter User Name : ";
    cin.ignore(); // Clear input buffer
    getline(std::cin, userName);
    
    while(true)
    {
        std::cout << "\nEnter Email : ";
        getline(std::cin, email);

        if(email.length() > 10 && email.substr(email.length() - 10) == "@gmail.com")
        {
            break;
        }
        else
        {
            std::cout << "Invalid email. Please enter a valid email ending with @gmail.com.\n";
        }
    }

    std::cout << "\nEnter Password : ";
    getline(std::cin, password);

    // Check if Data folder exists; if not, create it
    if (!fs::exists(folderPath)) {
        fs::create_directory(folderPath);
    }

    // Load existing data if file exists
    std::ifstream inFile(filePath);
    if (inFile.is_open()) {
        inFile >> usersData;
        inFile.close();
    }

    // Add new user data to JSON
    json newUser = {
        {"Name", userName},
        {"Email", email},
        {"Password", password}
    };
    usersData.emplace_back(newUser);

    // Write the updated data to the JSON file
    std::ofstream outFile(filePath);
    outFile << usersData.dump(4); // Pretty print with 4 spaces indentation
    outFile.close();

    std::cout << "Sign-Up successful!\n";
}

bool Temp::login() {
    bool is_opened = false;
    std::cout << "------------------LOGIN------------------" << std::endl;
    std::cout << "Enter Your User Name : ";
    cin.ignore(); // Clear input buffer
    getline(std::cin, searchName);
    std::cout << "Enter Your Password : ";
    getline(std::cin, searchPass);

    // Load existing data
    std::ifstream inFile(filePath);
    if (inFile.is_open()) {
        inFile >> usersData;
        inFile.close();
        is_opened = true;
    } else {
        std::cout << "Error opening the file. Please sign up first.\n";
        return is_opened;
    }

    // Search for the user in JSON data
    for (auto& user : usersData) {
        if (user["Name"] == searchName && user["Password"] == searchPass) {
            std::cout << "\nAccount Login Successfully...!" << std::endl;
            std::cout << "User Name : " << user["Name"] << std::endl;
            std::cout << "User Email : " << user["Email"] << std::endl;
            return is_opened;
        }
    }

    std::cout << "Invalid user name or password!\n";

    return is_opened;
}

void Temp::forget() {
    std::cout << "\nEnter your email: ";
    cin.ignore(); // Clear input buffer
    getline(std::cin, searchEmail);

    // Load existing data
    std::ifstream inFile(filePath);
    if (inFile.is_open()) {
        inFile >> usersData;
        inFile.close();
    } else {
        std::cout << "Error opening the file.\n";
        return;
    }

    // Search for the user by email
    for (auto& user : usersData) {
        if (user["Email"] == searchEmail) {
            std::cout << "Account Found..!" << std::endl;
            std::cout << "Your user name is : " << user["Name"] << std::endl;
            std::cout << "Your password is : " << user["Password"] << std::endl;
            return;
        }
    }

    std::cout << "Account not found!\n";
}