#include "customer.h"
#include "savingAccount.h"
#include "MilesAccount.h"
#include <iostream>

/**
 * @brief Default constructor for the Customer class.
 * Sets the name and ID to "Unknown" and reserves space for 10 accounts.
 */
Customer::Customer() : m_name("Unknown"), m_id("Unknown") {
    accounts.reserve(10);  // Limit to 10 accounts
    std::cout << "Default Customer Constructor" << std::endl;
}

/**
 * @brief Parameterized constructor for the Customer class.
 * @param name The customer's name.
 * @param id The customer's unique ID.
 */
Customer::Customer(const std::string& name, const std::string& id) : m_name(name), m_id(id) {
    accounts.reserve(10);  // Limit to 10 accounts
    std::cout << "Parameterized Customer Constructor" << std::endl;
}

/**
 * @brief Creates a bank account for the customer.
 * @param accountType The type of the account ("Saving" or "Miles").
 * @param name The customer's name.
 * @param id The customer's unique ID.
 * 
 * @throw std::invalid_argument if the account type is invalid.
 */
void Customer::createAccount(const std::string& accountType, const std::string& name, const std::string& id) {
    std::shared_ptr<BankAccount> account;

    if (accountType == "Miles") {
        account = std::make_shared<MilesAccount>();  // Creating MilesAccount
    } else if (accountType == "Saving") {
        account = std::make_shared<SavingAccount>();  // Creating SavingAccount
    } else {
        throw std::invalid_argument("Invalid account type: " + accountType);
    }

    accounts.emplace_back(account);  // Add the account to the customer's list
    m_name = name;
    m_id = id;
    displayCustomerInfo();
}

/**
 * @brief Displays the customer's information.
 * This includes the customer's name and unique ID.
 */
void Customer::displayCustomerInfo() const {
    std::cout << "Customer Name: " << m_name << "\n"
              << "Customer ID: "   << m_id << "\n";
}

/**
 * @brief Retrieves a bank account by index.
 * @param index The index of the account to retrieve (default is 0).
 * @return A shared pointer to the bank account at the specified index.
 * 
 * @throw std::out_of_range if the index is out of range.
 */
std::shared_ptr<BankAccount> Customer::getAccount(int index) const {
    if (index >= 0 && index < accounts.size()) {
        return accounts[index];
    }
    throw std::out_of_range("Account index is out of range: " + std::to_string(index));
}
