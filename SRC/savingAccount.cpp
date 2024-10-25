#include "savingAccount.h"
#include <random>

/**
 * @brief Default constructor for SavingAccount.
 * Initializes the account with a 2% interest rate and assigns a random account ID.
 */
SavingAccount::SavingAccount() : interest(0.02) {
    bankAccountID();
    balance = 0.00;
    name = "Saving Account";
    std::cout << "Saving Account created!" << std::endl;
}

/**
 * @brief Withdraws money from the savings account.
 * @param amount The amount to withdraw.
 * 
 * If the balance is greater than or equal to the amount, the withdrawal is successful.
 * Otherwise, an "Insufficient funds" message is displayed.
 */
void SavingAccount::withdraw(double amount) {
    if (balance >= amount) {
        balance -= amount;
        std::cout << "Withdrew: $" << amount << std::endl;
    } else {
        std::cout << "Insufficient funds!" << std::endl;
    }
}

/**
 * @brief Deposits money into the savings account.
 * @param amount The amount to deposit.
 * 
 * Adds the deposited amount to the account balance.
 */
void SavingAccount::deposit(double amount) {
    balance += amount;
    std::cout << "Deposit successful. New balance: $" << balance << "\n";
}

/**
 * @brief Transfers money from the savings account to another account.
 * @param amount The amount to transfer.
 * @param targetAccount The target bank account to receive the money.
 * 
 * If the balance is greater than or equal to the transfer amount, 
 * the transfer is successful. Otherwise, an "Insufficient funds" message is displayed.
 */
void SavingAccount::transferMoney(double amount, BankAccount& targetAccount) {
    if (balance >= amount) {
        balance -= amount;
        targetAccount.deposit(amount);
        std::cout << "Transferred: $" << amount << " to " << targetAccount.getAccountName() << std::endl;
    } else {
        std::cout << "Insufficient funds for transfer!" << std::endl;
    }
}

/**
 * @brief Checks the balance of the savings account, including interest.
 * @return The balance with interest applied.
 * 
 * The balance is increased by the interest rate (e.g., 2%).
 */
double SavingAccount::checkBal() const {
    return balance + (balance * interest);  // Balance plus interest
}

/**
 * @brief Generates a random account ID for the savings account.
 * 
 * Uses a random number generator to assign a unique account ID.
 */
void SavingAccount::bankAccountID(){
    // Using a better random generator
    std::random_device rd;  // Seed generator
    std::mt19937 rng(rd()); // Mersenne Twister random number engine
    std::uniform_int_distribution<int> dist(10000, 99999);  // Account ID range

    accountId = dist(rng);  // Assign random account ID
}

/**
 * @brief Gets the unique account ID of the savings account.
 * @return The account ID.
 */
int SavingAccount::getAccountId() const {
    return accountId;
}

/**
 * @brief Gets the current balance of the savings account.
 * @return The account balance.
 */
double SavingAccount::getBalance() const {
    return balance;
}

/**
 * @brief Gets the name of the savings account.
 * @return The account name (i.e., "Saving Account").
 */
std::string SavingAccount::getAccountName() const {
    return name;
}
