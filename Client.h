#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <optional>
#include <cstring>
#include "Command.h"

#pragma once

class Bank {
private:
    std::vector<std::shared_ptr<Account>> list;
//                                          ^ 0 - поле, под которым ничего не лежит, и проект упадёт, если к нему обратиться
    Invoker invoker;

public:
    std::string bank_name;

    class Client {
    private:
        std::string name;
        std::string surname;
        std::string address;
        size_t passport;
        size_t debit_account = 0;
        size_t credit_account = 0;
        size_t deposit = 0;
        double fine = 1;

        [[nodiscard]] size_t GetPassport() const;
        [[nodiscard]] std::string GetAddress() const;

    public:
        const size_t id;

        Client(std::string&, std::string&, size_t, std::string&, size_t);

        void AddDebitAccount(size_t);
        void AddCreditAccount(size_t);
        void AddDeposit(size_t);

        [[nodiscard]] std::pair<std::string, std::string> GetName() const;

        [[nodiscard]] size_t GetAccountId(size_t choice) const;
        [[nodiscard]] size_t GetDebitAccountId() const;
        [[nodiscard]] size_t GetCreditAccountId() const;
        [[nodiscard]] size_t GetDepositId() const;
    };

private:
    friend class AccountManage;
    double GetAccountBalance(size_t acc) { return list[acc]->GetBalance(); }

    size_t MakeNewAccount(size_t, double);

    double commission;
    double limit;
    size_t acceptableDifference;

    std::vector<std::unique_ptr<Client>> clients;
    friend class BankInterface;

public:
    size_t ClientsCount();
    size_t TransactionCount();

    Bank(std::string name, double commission, double limit, size_t acceptableDifference): bank_name(name), commission(commission), limit(limit), acceptableDifference(acceptableDifference) {
      list.push_back(nullptr);
    }
    // Я не знаю почему, но конструкторы выносить нельзя. Если попытаться, то упадёт с неизвестными мне ошибками

    ~Bank() {}

    void AddClient(std::string, std::string, std::string, size_t);
    void AddAccount(size_t, size_t, double);
    void AddTransaction(size_t, size_t, size_t, double, bool, size_t);
};