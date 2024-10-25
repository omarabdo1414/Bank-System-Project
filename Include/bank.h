#ifndef H_BANK
#define H_BANK

#include <string>

class BankAccount {
protected:
    double balance;
    std::string name;  // Use std::string for better memory management

public:
    virtual void withdraw(double amount) = 0;
    virtual void deposit(double amount) = 0;
    virtual void transferMoney(double amount, BankAccount& targetAccount) = 0;

    // Getter methods for account details
    virtual int getAccountId() const = 0;
    virtual double getBalance() const = 0;
    virtual std::string getAccountName() const = 0;

    // Virtual destructor to ensure proper cleanup in derived classes
    virtual ~BankAccount() = default;
};

#endif
