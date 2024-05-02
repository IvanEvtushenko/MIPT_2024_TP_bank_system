#include <iostream>
#include <vector>
#include <memory>
#include "Account.h"

#pragma once


class Transaction {
public:
    virtual double Execute() = 0;
    virtual double Abort() = 0;
};


class WithdrawMoney: public Transaction {
private:
    std::shared_ptr<Account> account;
    double count = 0;

public:
    bool status = true; // true -> the command was executed

    WithdrawMoney(std::shared_ptr<Account>, double);
    double Execute() override;
    double Abort() override;
};


class ReplenishAccount: public Transaction {
private:
    std::shared_ptr<Account> account;
    double count = 0;

public:
    bool status = true;

    ReplenishAccount(std::shared_ptr<Account>, double);
    double Execute() override;
    double Abort() override;
};


class ShowBalance: public Transaction {
private:
    std::shared_ptr<Account> account;
    double count = 0;

public:
    bool status = true;

    ShowBalance(std::shared_ptr<Account>, double);
    double Execute() override;
    double Abort() override;
};


class Invoker {
private:
    std::vector<std::unique_ptr<Transaction>> listOfTransaction;
    void AddTransaction(std::unique_ptr<Transaction>);

public:
    size_t TransactionCount();

    explicit Invoker() {};
    void UserInput(size_t, std::shared_ptr<Account>, double, bool, size_t);
};