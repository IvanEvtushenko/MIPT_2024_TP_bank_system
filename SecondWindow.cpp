 #include "SecondWindow.h"

Dialog::Dialog(Bank* active_bank, QWidget *parent): active_bank(active_bank), QDialog(parent) {
  create_client = new QPushButton("Создать клиента");
  select_client.setText("Выберете банк для дальнейших действий");
  select_client.setReadOnly(true);
  client_menu = new QComboBox(this);
  abort_transaction = new QPushButton("Отменить транзакцию");

  layout_client = new QVBoxLayout(this);
  layout_client->addWidget(create_client);
  layout_client->addWidget(&select_client);
  layout_client->addWidget(client_menu);
  layout_client->addWidget(abort_transaction);

  connect(create_client, &QPushButton::clicked, this, &Dialog::ClickedButton);
  connect(client_menu, &QComboBox::activated, this, &Dialog::MenuActivated);
  connect(abort_transaction, &QPushButton::clicked, this, &Dialog::ClickedButton2);
}

Dialog::~Dialog() { }


void Dialog::ClickedButton() {
  qDebug("Создание клиента начато успешно!");
  // TODO форма для ручного добавления клиента, пока заглушка
  char name[] = "Ivan";
  char surname[] = "Evtushenko";
  char address[] = "Piter";
  size_t passport = 1;
  active_bank->AddClient(name, surname, address, 1);
}

void Dialog::MenuActivated(int index) {
  // Создаём новое окно и передаём туда выбранный пользователем банк и созданного клиента
//  active_client_ex = new ;
//  active_client_ex->setModal(true);
//  active_client_ex->exec();
}

void Dialog::ClickedButton2() {
  qDebug("Отмена транзакции начата успешно!");
  size_t operation_id; // id транзакции
  active_bank->AddTransaction(0, 0, 0, 0, true, operation_id);

}
