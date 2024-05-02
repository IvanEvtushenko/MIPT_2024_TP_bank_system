#include "AddBankForm.h"
#include "BankMenu.h"

AddBank::AddBank(std::vector<Bank*>* banks_array, BankMenu* parent): banks_array(banks_array), QWidget(nullptr) {
  label_bank_name = new QLabel("Введите название банка");
  label_bank_commission = new QLabel("Установите комиссию банка");
  label_bank_limit = new QLabel("Установите лимит отрицательного баланса");
  label_bank_time_limit = new QLabel("Установите время, после которого можно снять депозит");

  bank_name = new QLineEdit();
  bank_commission = new QLineEdit();
  bank_limit = new QLineEdit();
  bank_time_limit = new QLineEdit();

  is_done = new QPushButton("Создать");

  layout_lines = new QFormLayout(this);
  layout_lines->addRow(label_bank_name, bank_name);
  layout_lines->addRow(label_bank_commission, bank_commission);
  layout_lines->addRow(label_bank_limit, bank_limit);
  layout_lines->addRow(label_bank_time_limit, bank_time_limit);
  layout_lines->addRow(is_done);

  parent_link = parent;

  connect(is_done, &QPushButton::clicked, this, &AddBank::ClickedButton);
}

AddBank::~AddBank() = default;

void AddBank::ClickedButton() {
  std::string name = bank_name->text().toStdString();
  double commission = std::stof(bank_commission->text().toStdString());
  double time = std::stof(bank_limit->text().toStdString());
  size_t time_limit = std::stoull(bank_time_limit->text().toStdString());
  banks_array->push_back(new Bank(name, commission, time, time_limit));
  parent_link->active_bank_adding_finished(name);
}