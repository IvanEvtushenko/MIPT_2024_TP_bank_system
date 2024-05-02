#include "BankInterface.h"
#include "AddClientForm.h"
#include "AccountManage.h"

BankInterface::BankInterface(Bank* active_bank, QWidget *parent): active_bank(active_bank), QWidget(parent) {
  label = new QLabel(QString::fromStdString(active_bank->bank_name));
  create_client = new QPushButton("Создать клиента");
  select_client = new QLabel("Выберете клиента для дальнейших действий");
  client_menu = new QComboBox(this);
  empty = new QLabel();
  abort_transaction = new QPushButton("Отменить транзакцию под номером ... ");
  number = new QLineEdit();

  layout_client = new QFormLayout(this);
  layout_client->addRow(label);
  layout_client->addRow(create_client);
  layout_client->addRow(select_client);
  layout_client->addRow(client_menu);
  layout_client->addRow(empty);
  layout_client->addRow(abort_transaction, number);


  active_client_adding_ex = new AddClient(active_bank, this);

  connect(create_client, &QPushButton::clicked, this, &BankInterface::ClickedButton);
  connect(client_menu, &QComboBox::activated, this, &BankInterface::MenuActivated);
  connect(abort_transaction, &QPushButton::clicked, this, &BankInterface::ClickedButton2);
}

BankInterface::~BankInterface() = default;


void BankInterface::active_client_adding_finished(std::string& name, std::string& surname) {
  client_menu->addItem(QString::fromStdString(name + " " + surname));
  this->show();
}

void BankInterface::MenuActivated(int index) {
  active_client_ex = new AccountManage(active_bank, &*active_bank->clients[index]);
  active_client_ex->setSizeIncrement(200, 0);
  active_client_ex->show();
}

void BankInterface::ClickedButton() {
  this->hide();
  active_client_adding_ex->setSizeIncrement(200, 0);
  active_client_adding_ex->show();
}

void BankInterface::ClickedButton2() {
  if (number->displayText().isEmpty()) {
    QMessageBox::information(this, tr("Ошибка заполнения формы"), tr("Убедитесь, что поле заполнено корректно"));
    return;
  }
  size_t operation_id = std::stoull(number->text().toStdString());
  if (operation_id >= active_bank->TransactionCount()) {
    QMessageBox::warning(this, tr("Ошибка отмены транзакции"), tr("Транзакции с введённым индексом не существует"));
    return;
  }
  try {
    active_bank->AddTransaction(0, 0, 0, 0, true, operation_id);
  } catch (CustomError error) {
    if (error.getErrorCode() == 2) {
      std::string massage = "Клиент, " + active_bank->clients[error.getClientID()]->GetName().first + " " +
                            active_bank->clients[error.getClientID()]->GetName().second + ", совершивший операцию №" +
                            std::to_string(operation_id) +
                            ", не имеет на счету достаточно средств для погашения задолженности, образовавшейся, "
                            "в связи с её отменой. Соответственно, банк принял решение составить иск об удержании "
                            "средств и направить его в суд на сумму " +
                            std::to_string(error.getArrears()) + " рублей. Его счета заморожены";
      active_bank->black_list.push_back(error.getClientID());
      QMessageBox::warning(this, tr("Подача заявления в суд"), tr(massage.c_str()));
    }
  }
}