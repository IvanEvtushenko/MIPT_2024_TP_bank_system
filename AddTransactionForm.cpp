#include "AddTransactionForm.h"
#include "BankMenu.h"
#include "CustomError.h"

AddingTransaction::AddingTransaction(Bank* active_bank, Bank::Client* active_client, AccountManage* parent): active_bank(active_bank), active_client(active_client), parent_link(parent), QWidget(nullptr) {
  label_client_name = new QLabel(QString::fromStdString(active_client->GetName().first + " " + active_client->GetName().second));
  acc_types_label = new QLabel("Выберете тип счёта к которому хотите применить операцию");
  trans_types_label = new QLabel("Выберете тип операции");
  amount_label = new QLabel("Введите сумму");

  acc_types = new QComboBox();
  acc_types->addItem("Дебетовый счёт");
  acc_types->addItem("Кредитный счёт");
  acc_types->addItem("Депозит");

  trans_types = new QComboBox();
  trans_types->addItem("Пополнить баланс");
  trans_types->addItem("Снять деньги");

  amount = new QLineEdit();

  is_done = new QPushButton("Создать");

  layout_form = new QFormLayout(this);
  layout_form->addRow(label_client_name);
  layout_form->addRow(acc_types_label, acc_types);
  layout_form->addRow(trans_types_label, trans_types);
  layout_form->addRow(amount_label, amount);
  layout_form->addRow(is_done);

  connect(is_done, &QPushButton::clicked, this, &AddingTransaction::ClickedButton);
  connect(acc_types, &QComboBox::activated, this, &AddingTransaction::AccTypesMenuActivated);
  connect(trans_types, &QComboBox::activated, this, &AddingTransaction::TransTypesMenuActivated);
}

AddingTransaction::~AddingTransaction() = default;


void AddingTransaction::AccTypesMenuActivated(int index) { acc_types_condition = index; }
void AddingTransaction::TransTypesMenuActivated(int index) { trans_types_condition = index; }

void AddingTransaction::ClickedButton() {
  double count = std::stod(amount->text().toStdString());
  try {
    active_bank->AddTransaction(active_client->id, trans_types_condition, acc_types_condition, count, false, 0);
  } catch (CustomError error) {
    if (error.getErrorCode() == 0) {
      QMessageBox::warning(this, tr("Ошибка снятия суммы"), tr("На балансе недостаточно средств"));
    } else if (error.getErrorCode() == 1) {
      QMessageBox::warning(this, tr("Ошибка снятия суммы"), tr("На данный момент невозможно снять деньги с депозита. Пожалуйста, попробуйте позже"));
    } else { std::cout << "Ну... тяжело" << std::endl; } // такого произойти не должно
  }
  parent_link->update_account_balance();
  this->close();
}