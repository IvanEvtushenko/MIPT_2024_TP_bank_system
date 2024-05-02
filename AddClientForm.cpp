#include "AddClientForm.h"
#include "BankMenu.h"

AddClient::AddClient(Bank* active_bank, BankInterface* parent): active_bank(active_bank), parent_link(parent), QWidget(nullptr) {
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

  connect(is_done, &QPushButton::clicked, this, &AddClient::ClickedButton);
}

AddClient::~AddClient() = default;


void AddClient::ClickedButton() {
  if (client_name->displayText().isEmpty() || client_surname->displayText().isEmpty()) {
    QMessageBox::warning(this, tr("Ошибка заполнения формы"), tr("Убедитесь, что все поля заполнены корректно"));
    counter = 0;
    return;
  }
  std::string name = client_name->text().toStdString();
  std::string surname = client_surname->text().toStdString();
  std::string address;
  size_t passport = 0;

  if (counter == 0 && (client_address->displayText().isEmpty() || client_passport->displayText().isEmpty())) {
    QMessageBox::information(this, tr("Информация"),
                             tr("Убедитесь, что все поля заполнены корректно. В случае отсутствия паспортных данных или адреса, на клиента будет наложен штраф в виде доп. комиссии. Если это была ошибка - заполните поля и отправьте форму ещё раз."));
    counter = 1;
    return;
  }

  if (!client_address->displayText().isEmpty()) { address = client_address->text().toStdString(); }
  if (!client_passport->displayText().isEmpty()) { passport = std::atoll(("0" + client_passport->text().toStdString()).data()); }
  counter = 0;

  active_bank->AddClient(name, surname, address, passport);
  parent_link->active_client_adding_finished(name, surname);
  this->hide();
}