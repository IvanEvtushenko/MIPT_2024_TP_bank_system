#include "AccountManage.h"
#include "AddTransactionWindow.h"

AccountManage::AccountManage(Bank* active_bank, Bank::Client* active_client): active_bank(active_bank), active_client(active_client), QWidget(nullptr) {
  label = new QLabel(QString::fromStdString(active_client->GetName().first + " " + active_client->GetName().second));

  label_debt = new QLabel("Баланс дебетового счёта");
  label_credit = new QLabel("Баланс кредитного счёта");
  label_dep = new QLabel("Баланс депозита");

  debt = new QPushButton("У клиента ещё нет дебетового счёта");
  credit = new QPushButton("У клиента ещё нет кредитного счёта");
  dep = new QPushButton("У клиента ещё нет депозита");

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
  debt->setFlat(true);
  debt->setText("0");
  debt->setEnabled(false);
}

void AccountManage::MakeCreditAccount() {
  active_bank->AddAccount(active_client->id, 1, 0);
  credit->setFlat(true);
  credit->setText("0");
  credit->setEnabled(false);
}

void AccountManage::MakeDepAccount() {
  active_bank->AddAccount(active_client->id, 2, 0);
  dep->setFlat(true);
  dep->setText("0");
  dep->setEnabled(false);
}

void AccountManage::AddTransaction() {
  active_transaction_adding = new AddingTransaction(active_bank, active_client, this);
  active_transaction_adding->show();
}

void AccountManage::active_trans_adding_finished() {
  debt->setText(QString::fromStdString(std::to_string(active_bank->list[active_client->GetDebitAccountId()]->GetBalance())));
  credit->setText(QString::fromStdString(std::to_string(active_bank->list[active_client->GetCreditAccountId()]->GetBalance())));
  dep->setText(QString::fromStdString(std::to_string(active_bank->list[active_client->GetDepositId()]->GetBalance())));
}
