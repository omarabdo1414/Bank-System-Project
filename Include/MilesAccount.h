#ifndef H_MILES_ACCOUNT
#define H_MILES_ACCOUNT

#include "bank.h"
#include "nlohmann/json.hpp"  // For handling JSON files
#include <string>
#include <vector>

#define BankName "National Bank"

class MilesAccount : public BankAccount
{
private:
    std::vector<std::string> m_rewards;
    int m_points;
    double interest;
    int accountId;

public:
    MilesAccount();
    MilesAccount(int points);

    // Override virtual methods from BankAccount
    void withdraw(double amount) override;
    void deposit(double amount) override;
    void transferMoney(double amount, BankAccount& targetAccount);
    void bankAccountID();

    // Reward system functions
    std::string claim(std::string code);
    void addPoints(int points);
    void addReward(std::string name, std::string password);

    int getAccountId() const override;

    double getBalance() const override;

    std::string getAccountName() const override;
};

#endif  // H_MILES_ACCOUNT
