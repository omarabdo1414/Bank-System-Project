#include "./MilesAccount.h"
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <random>
#include "nlohmann/json.hpp"

using json = nlohmann::json;

/**
 * @file MilesAccount.cpp
 * @brief Implementation of the MilesAccount class.
 * 
 * This class represents a type of bank account with reward points and miles, inheriting from BankAccount.
 */

/**
 * @brief Default constructor for MilesAccount.
 * 
 * Initializes account with 50 reward points.
 */
MilesAccount::MilesAccount() : m_points(50), interest(0.02) {
    accountId = accountId = rand() % 10000;
    name = "Miles Account";
    balance = 0;  // Initial balance set to 0
    std::cout << "Welcome to the " << BankName << "\n";
    std::cout << "You have 50 points for signing in as a Miles Account Customer\n";
}

/**
 * @brief Parameterized constructor for MilesAccount.
 * 
 * @param points Initial reward points for the account.
 * @param id The id for the account, because each account has a unique id
 */
MilesAccount::MilesAccount(int points) : m_points(points), interest(0.02) {
    accountId = accountId = rand() % 10000;
    balance = 0;  // Initial balance set to 0
    name = "Miles Account";
    std::cout << "Welcome to the " << BankName << "\n";
    std::cout << "You have 50 points for signing in as a Miles Account Customer\n";
}

/**
 * @brief Withdraws an amount from the account balance.
 * 
 * @param amount Amount to withdraw.    
 */
void MilesAccount::withdraw(double amount) {
    if (balance >= amount)
    {
        balance -= amount;
        std::cout << "Withdrawal successful. New balance: $" << balance << "\n";
    }
    else
    {
        std::cout << "Insufficient funds.\n";
    }
}

/**
 * @brief Deposits an amount into the account balance.
 * 
 * @param amount Amount to deposit.
 */
void MilesAccount::deposit(double amount) {
    balance += amount;
    std::cout << "Deposit successful. New balance: $" << balance << "\n";
}

/**
 * @brief Transfers an amount to another account.
 * 
 * @param amount Amount to transfer.
 * @param targetAccount Pointer to the target account to which money will be transferred.
 */
void MilesAccount::transferMoney(double amount, BankAccount& targetAccount) {
    if (amount <= balance)
    {
        balance -= amount;
        targetAccount.deposit(amount);
        std::cout << "Transferred $" << amount << " to account ID " << targetAccount.getAccountId() << std::endl;
    }
    else
    {
        std::cout << "Insufficient balance for transfer!" << std::endl;
    }
}

void MilesAccount::bankAccountID(){
    // Using a better random generator
    std::random_device rd;  // Seed generator
    std::mt19937 rng(rd()); // Mersenne Twister random number engine
    std::uniform_int_distribution<int> dist(10000, 99999);  // Account ID range

    accountId = dist(rng);  // Assign random account ID
}

/**
 * @brief Claims a reward using a reward code.
 * 
 * @param code Reward code to claim.
 * @return std::string Message indicating success or failure of the reward claim.
 */
std::string MilesAccount::claim(std::string code) {
    auto it = std::find(m_rewards.begin(), m_rewards.end(), code);
    if (it != m_rewards.end())
    {
        return "You have claimed $40";
    }
    return "Invalid reward code.";
}

/**
 * @brief Adds points to the account.
 * 
 * @param points Number of points to add.
 */
void MilesAccount::addPoints(int points) {
    m_points += points;
    std::cout << points << " points added. Total points: " << m_points << "\n";
}

/**
 * @brief Adds rewards to the system, restricted to admin users.
 * 
 * Admin credentials are validated using JSON data stored in a file.
 * 
 * @param name Admin username.
 * @param password Admin password.
 */
void MilesAccount::addReward(std::string name, std::string password) {
    // Load existing admin data from a JSON file
    std::ifstream inFile("./build/Data/Login_data.json");  // Adjust the path as necessary
    if (!inFile.is_open())
    {
        std::cout << "Failed to open the file." << std::endl;
        return;
    }

    json adminData;
    inFile >> adminData;  // Read JSON data from file
    inFile.close();

    // Check if the provided name and password are valid
    bool isValidAdmin = false;
    for (const auto& user : adminData)
    {
        if (user["Name"] == name && user["Password"] == password)
        {
            isValidAdmin = true;
            break;
        }
    }

    // If credentials are valid, proceed to add rewards
    if (isValidAdmin)
    {
        int numberOfRewards;
        std::cout << "Enter the number of rewards to add: ";
        std::cin >> numberOfRewards;

        std::cin.ignore();  // Clear input buffer after the number of rewards input
        for (int i = 0; i < numberOfRewards; ++i)
        {
            std::string reward;
            std::cout << "Enter reward " << (i + 1) << ": ";
            std::getline(std::cin, reward);  // Read the reward as a full string
            m_rewards.emplace_back(reward);  // Add reward to the vector
        }

        std::cout << numberOfRewards << " rewards added successfully!" << std::endl;
    }
    else
    {
        std::cout << "Invalid admin credentials. Access denied." << std::endl;
    }
}

/**
 * @brief Returns the account ID.
 * 
 * @return int The ID of the account.
 */
int MilesAccount::getAccountId() const {
    return accountId;
}

/**
 * @brief Returns the current balance of the account.
 * 
 * @return double The balance of the account.
 */
double MilesAccount::getBalance() const {
    return balance;
}

/**
 * @brief Returns the name of the account holder.
 * 
 * @return std::string The name of the account holder.
 */
std::string MilesAccount::getAccountName() const {
    return name;
}
