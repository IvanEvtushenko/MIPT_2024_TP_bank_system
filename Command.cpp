#include "Command.h"

#pragma once


WithdrawMoney::WithdrawMoney(std::shared_ptr<Account> account, double count): account(account), count(count) {}
double WithdrawMoney::Execute() {
  try { account->ReduceBalance(count); }
  catch (CustomError& ex) {
    std::cout << ex.what() << "\n";
    count = 0;
    Abort();
  }
  return account->GetBalance();
}
double WithdrawMoney::Abort() {
  if (!status) { return account->GetBalance(); }
  status = false;
   account->IncreaseBalance(count);
  return account->GetBalance();
}


ReplenishAccount::ReplenishAccount(std::shared_ptr<Account> account, double count): account(account), count(count) {}
double ReplenishAccount::Execute() {
  account->IncreaseBalance(count);
  return account->GetBalance();
}
double ReplenishAccount::Abort() {
  if (!status) { return account->GetBalance(); }
  status = false;
  try { account->ReduceBalance(count); }
  catch (CustomError& ex) {
    double arrears = count - account->GetBalance();
    throw CustomError("the client has a fine now", 2, arrears);
    // TODO Добавить клиенту счёт с отрицательным балансом, который нужно будет погасить. На все остальные же счета будет наложен штраф 80%
  }
  return account->GetBalance();
}


ShowBalance::ShowBalance(std::shared_ptr<Account> account, double count): account(account), count(count) {}
double ShowBalance::Execute() { return account->GetBalance(); }
double ShowBalance::Abort() { return account->GetBalance(); }


void Invoker::AddTransaction(std::unique_ptr<Transaction> ptr) {
  listOfTransaction.push_back(std::move(ptr));
}

void Invoker::UserInput(size_t choice_tr, std::shared_ptr<Account> account, double count = 0, bool abort = false, size_t operationId = 0) {
  if (abort) { listOfTransaction[operationId]->Abort(); }
  else {
    switch (choice_tr) {
      case 0:
        AddTransaction(std::move(std::unique_ptr<ShowBalance>{new ShowBalance(account, count)}));
        (*(listOfTransaction.end() - 1))->Execute();
        std::cout << account->GetBalance() << " executed\n";
        break;
      case 1:
        AddTransaction(std::move(std::unique_ptr<WithdrawMoney>{new WithdrawMoney(account, count)}));
        (*(listOfTransaction.end() - 1))->Execute();
        std::cout << account->GetBalance() << " executed\n";
        break;
      case 2:
        AddTransaction(std::move(std::unique_ptr<ReplenishAccount>{new ReplenishAccount(account, count)}));
        (*(listOfTransaction.end() - 1))->Execute();
        std::cout << account->GetBalance() << " executed\n";
        break;
      default:
        std::cout << "something went wrong\n";
        break;
    }
  }
}