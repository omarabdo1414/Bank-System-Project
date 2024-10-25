#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>
#include <memory>
#include "bank.h"

/**
 * @class Customer
 * @brief Represents a bank customer who can have multiple accounts.
 */
class Customer {
private:
    std::string m_name;  ///< The customer's name.
    std::string m_id;    ///< The customer's unique ID.
    std::vector<std::shared_ptr<BankAccount>> accounts;  ///< A vector holding the customer's bank accounts.

public:
    /**
     * @brief Default constructor for the Customer class.
     * Initializes the customer's name and ID to "Unknown".
     */
    Customer();

    /**
     * @brief Parameterized constructor for the Customer class.
     * @param name The customer's name.
     * @param id The customer's unique ID.
     */
    Customer(const std::string& name, const std::string& id);

    /**
     * @brief Creates a new bank account for the customer.
     * @param accountType The type of account ("Saving" or "Miles").
     * @param name The customer's name.
     * @param id The customer's unique ID.
     * 
     * @throw std::invalid_argument if the account type is invalid.
     */
    void createAccount(const std::string& accountType, const std::string& name, const std::string& id);

    /**
     * @brief Displays the customer's information, including name and ID.
     */
    void displayCustomerInfo() const;

    /**
     * @brief Retrieves an account from the customer’s list of accounts by index.
     * @param index The index of the account in the list (default is 0).
     * @return A shared pointer to the bank account.
     * 
     * @throw std::out_of_range if the index is invalid.
     */
    std::shared_ptr<BankAccount> getAccount(int index = 0) const;

    /**
     * @brief Gets the customer's name.
     * @return The customer's name.
     */
    std::string getName() const { return m_name; }

    /**
     * @brief Gets the customer's ID.
     * @return The customer's unique ID.
     */
    std::string getId() const { return m_id; }
};

#endif
