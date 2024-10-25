#include "bank.h"
#include <iostream>

/**
 * @brief A class representing a savings account, derived from the BankAccount class.
 * 
 * This class provides specific functionalities for savings accounts, 
 * including interest accumulation, withdrawals, deposits, and money transfers.
 */
class SavingAccount : public BankAccount
{
private:
    double interest;   /**< The interest rate applied to the savings account. */
    int accountId;     /**< The unique identifier for the savings account. */

public:
    /**
     * @brief Default constructor for SavingAccount.
     * Initializes the account with a default interest rate and assigns a random account ID.
     */
    SavingAccount();

    /**
     * @brief Withdraws an amount from the account balance.
     * @param amount The amount to withdraw.
     * 
     * If the balance is insufficient, it will display an error message.
     */
    void withdraw(double amount) override;

    /**
     * @brief Deposits an amount into the account balance.
     * @param amount The amount to deposit.
     */
    void deposit(double amount) override;

    /**
     * @brief Transfers an amount from this account to another bank account.
     * @param amount The amount to transfer.
     * @param targetAccount The target account where the money will be transferred.
     */
    void transferMoney(double amount, BankAccount& targetAccount) override;

    /**
     * @brief Checks the account balance with interest applied.
     * @return The account balance including interest.
     */
    double checkBal() const;

    /**
     * @brief Generates a random unique account ID for the savings account.
     * 
     * Uses a random number generator to assign an account ID.
     */
    void bankAccountID();

    /**
     * @brief Gets the unique account ID of the savings account.
     * @return The account ID.
     */
    int getAccountId() const override;

    /**
     * @brief Gets the current balance of the savings account.
     * @return The account balance.
     */
    double getBalance() const override;

    /**
     * @brief Gets the name of the account type.
     * @return The name of the account type (i.e., "Saving Account").
     */
    std::string getAccountName() const override;
};
