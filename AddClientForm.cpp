#include "AddClientWindow.h"
#include "BankMenu.h"

AddClientWindow::AddClientWindow(Bank* active_bank, BankInterface* parent): active_bank(active_bank), parent_link(parent), QWidget(nullptr) {
  label_client_name = new QLabel("Введите имя клиента");
  label_client_surname = new QLabel("Введите фамилию клиента");
  label_client_address = new QLabel("Введите адрес клиента");
  label_client_passport = new QLabel("Введите паспортные данные клиента");

  client_name = new QLineEdit();
  client_surname = new QLineEdit();
  client_address = new QLineEdit();
  client_passport = new QLineEdit();

  is_done = new QPushButton("Добавить");

  layout_lines = new QFormLayout(this);
  layout_lines->addRow(label_client_name, client_name);
  layout_lines->addRow(label_client_surname, client_surname);
  layout_lines->addRow(label_client_address, client_address);
  layout_lines->addRow(label_client_passport, client_passport);
  layout_lines->addRow(is_done);

  connect(is_done, &QPushButton::clicked, this, &AddClientWindow::ClickedButton);
}

AddClientWindow::~AddClientWindow() = default;


void AddClientWindow::ClickedButton() {
  std::string name = client_name->text().toStdString();
  std::string surname = client_surname->text().toStdString();
  std::string address = client_address->text().toStdString();
  size_t passport = std::stoull(client_passport->text().toStdString());

  active_bank->AddClient(name, surname, address, passport);
  parent_link->active_client_adding_finished(name, surname);
  this->hide();
}