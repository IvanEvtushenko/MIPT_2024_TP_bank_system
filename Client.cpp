#include "Client.h"

#pragma once

[[nodiscard]] size_t Bank::Client::GetPassport() const { return passport; }
[[nodiscard]] std::string Bank::Client::GetAddress() const { return address; }

Bank::Client::Client(std::string& name, std::string& surname, size_t id, std::string& address, size_t passport = 0) : name(name), surname(surname), id(id), address(address), passport(passport) {
  if (passport == 0) { fine -= 0.3; }
  if (address.empty()) { fine -= 0.3; }
}

bool Bank::IsBlack(size_t id) {
  for (auto i: black_list) if (i == id) return true;
  return false;
}

void Bank::Client::AddDebitAccount(size_t id) { debit_account = id; }
void Bank::Client::AddCreditAccount(size_t id) { credit_account = id; }
void Bank::Client::AddDeposit(size_t id) { deposit = id; }
[[nodiscard]] std::pair<std::string, std::string> Bank::Client::GetName() const { return {name, surname}; }

[[nodiscard]] size_t Bank::Client::GetAccountId(size_t choice) const {
  switch (choice) {
    case 0:
      return GetDebitAccountId();
    case 1:
      return GetCreditAccountId();
    case 2:
      return GetDepositId();
    default:
      std::cout << "something went wrong (1), bad choice account. Your index is " << choice << "\n";
      break;
  }
  return -1;
}
[[nodiscard]] size_t Bank::Client::GetDebitAccountId() const { return debit_account; }
[[nodiscard]] size_t Bank::Client::GetCreditAccountId() const { return credit_account; }
[[nodiscard]] size_t Bank::Client::GetDepositId() const { return deposit; }

size_t Bank::MakeNewAccount(size_t choice, double count, size_t client_id) {
  switch(choice) {
    case 0:
      list.push_back(std::make_shared<DebitAccount>(client_id, count));
      break;
    case 1:
      list.push_back(std::make_shared<CreditAccount>(client_id, count, limit, commission));
      break;
    case 2:
      list.push_back(std::make_shared<Deposit>(client_id, count, acceptableDifference));
      break;
    default:
      std::cout << "something went wrong (2), bad choice account. Your index is " << choice << "\n";
      break;
  }
  return list.size() - 1;
}

void Bank::AddClient(std::string name, std::string surname, std::string address = "", size_t passport = 0) {
  clients.push_back(std::make_unique<Client>(name, surname, clients.size(), address, passport));
}

void Bank::AddAccount(size_t client_id, size_t choice_acc, double count = 0) {
  switch (choice_acc) {
    case 0:
      clients[client_id]->AddDebitAccount(MakeNewAccount(choice_acc, count, client_id));
      break;
    case 1:
      clients[client_id]->AddCreditAccount(MakeNewAccount(choice_acc, count, client_id));
      break;
    case 2:
      clients[client_id]->AddDeposit(MakeNewAccount(choice_acc, count, client_id));
      break;
    default:
      std::cout << "something went wrong (3), bad choice account. Your index is " << choice_acc << "\n";
      break;
  }
}

void Bank::AddTransaction(size_t client_id, size_t choice_tr, size_t choice_acc, double count = 0, bool abort = false, size_t operationId = 0) {
  if (IsBlack(client_id)) throw CustomError("Client in black list", 3, 0);
  invoker.UserInput(choice_tr, list[clients[client_id]->GetAccountId(choice_acc)], count, abort, operationId);
}

size_t Bank::ClientsCount() { return clients.size(); }

size_t Bank::TransactionCount() { return invoker.TransactionCount(); }