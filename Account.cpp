#include "Account.h"

#pragma once

DebitAccount& DebitAccount::IncreaseBalance(double count) {
  balance += count;
  return *this;
}

DebitAccount& DebitAccount::ReduceBalance(double count) {
  if (balance >= count - precision) {
    balance -= count - precision;
  } else {
    throw CustomError("Insufficient funds to perform the operation on the account", 0);
  }
  return *this;
}

DebitAccount& DebitAccount::AssignBalance(double count) { balance = count; return *this; }

[[nodiscard]] double DebitAccount::GetBalance() const { return balance; }


CreditAccount& CreditAccount::IncreaseBalance(double count) {
  if (balance < 0) { balance += commission * balance; }
  balance += count;
  return *this;
}

CreditAccount& CreditAccount::ReduceBalance(double count) {
  if (limit <= balance - count + precision + commission * balance) {
    balance -= count - precision;
    if (balance < 0) { balance += commission * balance; }
  } else {
    throw CustomError("Insufficient funds to perform the operation on the account", 0);
  }
  return *this;
}

CreditAccount& CreditAccount::AssignBalance(double count) { balance = count + limit; return *this; }

[[nodiscard]] double CreditAccount::GetBalance() const { return balance; }


Deposit& Deposit::IncreaseBalance(double count) { balance += count; return *this; }

Deposit& Deposit::ReduceBalance(double count) {
  if (std::time_t(nullptr) - startTime >= acceptableDifference) DebitAccount::ReduceBalance(count);
  else throw CustomError("It is currently not possible to withdraw money from the account", 1);
  return *this;
}

Deposit& Deposit::AssignBalance(double count) { balance = count; return *this; }

[[nodiscard]] double Deposit::GetBalance() const { return balance; }