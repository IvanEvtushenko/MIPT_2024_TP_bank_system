#include <iostream>
#include <memory>
#include <ctime>
#include "CustomError.h"

#pragma once

class Account {
    size_t owner_id;
    friend class WithdrawMoney;
    friend class ReplenishAccount;
    friend class ShowBalance;

public:
    Account(size_t owner_id): owner_id(owner_id) {}

    virtual Account& IncreaseBalance(double) = 0;
    virtual Account& ReduceBalance(double) = 0;
    virtual Account& AssignBalance(double) = 0;

    [[nodiscard]] virtual double GetBalance() const = 0;

//    virtual ~Account() = 0;
};


class DebitAccount: public Account {
protected:
    double balance = 0;

private:
    const double precision = 0.00000001;

public:
    explicit DebitAccount(size_t owner_id, const double balance): Account(owner_id), balance(balance) {}

    DebitAccount& IncreaseBalance(double) override;
    DebitAccount& ReduceBalance(double) override;
    DebitAccount& AssignBalance(double) override;

    [[nodiscard]] double GetBalance() const override;
};


class CreditAccount: public Account {
protected:
    double balance = 0;

private:
    const double precision = 0.00000001;
    double limit = 0;
    double commission = 0;

public:
    CreditAccount (size_t owner_id, const double balance, const double limit, const double commission): Account(owner_id), balance(balance), limit(limit), commission(commission) {}

    CreditAccount& IncreaseBalance(double) override;
    CreditAccount& ReduceBalance(double) override;
    CreditAccount& AssignBalance(double) override;

    [[nodiscard]] double GetBalance() const override;
};


class Deposit: public DebitAccount {
private:
    const double precision = 0.00000001;
    std::time_t startTime;
    size_t acceptableDifference;

public:
    Deposit(size_t owner_id, const double count, const size_t timeForBlock): DebitAccount(owner_id, count), acceptableDifference(timeForBlock), startTime(std::time_t(nullptr)) {}

    Deposit& IncreaseBalance(double) override;
    Deposit& ReduceBalance(double) override;
    Deposit& AssignBalance(double) override;

    [[nodiscard]] double GetBalance() const override;
};