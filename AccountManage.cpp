#include "AccountManage.h"
#include "AddTransactionForm.h"

AccountManage::AccountManage(Bank* active_bank, Bank::Client* active_client): active_bank(active_bank), active_client(active_client), QWidget(nullptr) {
  label = new QLabel(QString::fromStdString(active_client->GetName().first + " " + active_client->GetName().second));

  label_debt = new QLabel("Баланс дебетового счёта");
  label_credit = new QLabel("Баланс кредитного счёта");
  label_dep = new QLabel("Баланс депозита");

  debt = new QPushButton();
  credit = new QPushButton();
  dep = new QPushButton();
  update_account_balance();

  create_transaction = new QPushButton("Добавить транзакцию");

  layout_lines = new QFormLayout(this);
  layout_lines->addRow(label);
  layout_lines->addRow(label_debt, debt);
  layout_lines->addRow(label_credit, credit);
  layout_lines->addRow(label_dep, dep);
  layout_lines->addRow(create_transaction);

  connect(debt, &QPushButton::clicked, this, &AccountManage::MakeDebtAccount);
  connect(credit, &QPushButton::clicked, this, &AccountManage::MakeCreditAccount);
  connect(dep, &QPushButton::clicked, this, &AccountManage::MakeDepAccount);
  connect(create_transaction, &QPushButton::clicked, this, &AccountManage::AddTransaction);
}

AccountManage::~AccountManage() = default;


void AccountManage::MakeDebtAccount() {
  active_bank->AddAccount(active_client->id, 0, 0);
  update_account_balance();
}

void AccountManage::MakeCreditAccount() {
  active_bank->AddAccount(active_client->id, 1, 0);
  update_account_balance();
}

void AccountManage::MakeDepAccount() {
  active_bank->AddAccount(active_client->id, 2, 0);
  update_account_balance();
}

void AccountManage::AddTransaction() {
  active_transaction_adding = new AddingTransaction(active_bank, active_client, this);
  active_transaction_adding->show();
}

void AccountManage::update_account_balance() {
  if (active_bank->list[active_client->GetDebitAccountId()]) {
    debt->setText(QString::fromStdString(
            std::to_string(active_bank->list[active_client->GetDebitAccountId()]->GetBalance())));
    debt->setEnabled(false);
    debt->setFlat(true);
  } else { debt->setText("У клиента ещё нет дебетового счёта"); }
  if (active_bank->list[active_client->GetCreditAccountId()]) {
    credit->setText(QString::fromStdString(
            std::to_string(active_bank->list[active_client->GetCreditAccountId()]->GetBalance())));
    credit->setEnabled(false);
    credit->setFlat(true);
  } else { credit->setText("У клиента ещё нет кредитного счёта"); }
  if (active_bank->list[active_client->GetDepositId()]) {
    dep->setText(
            QString::fromStdString(std::to_string(active_bank->list[active_client->GetDepositId()]->GetBalance())));
    dep->setEnabled(false);
    dep->setFlat(true);
  } else { dep->setText("У клиента ещё нет депозита"); }
}
