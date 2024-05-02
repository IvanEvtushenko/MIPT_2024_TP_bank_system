#include "BankMenu.h"
#include "AddBankForm.h"
#include "BankInterface.h"
#include <string>

BankMenu::BankMenu(QWidget* parent): banks_array(0), QWidget(parent) {
  create_bank = new QPushButton("Cоздать банк");
  select_bank = new QLabel("Выберете банк для дальнейших действий");
  bank_menu = new QComboBox(this);

  layout_bank = new QVBoxLayout(this);
  layout_bank->addWidget(create_bank);
  layout_bank->addWidget(select_bank);
  layout_bank->addWidget(bank_menu);

  active_bank_adding_ex = new AddBank(&banks_array, this);

  connect(create_bank, &QPushButton::clicked, this, &BankMenu::ClickedButton);
  connect(bank_menu, &QComboBox::activated, this, &BankMenu::MenuActivated);
}

BankMenu::~BankMenu() = default;


void BankMenu::active_bank_adding_finished(std::string& name) {
  bank_menu->addItem(QString::fromStdString(name));
  active_bank_adding_ex->hide();
  this->show();
}

void BankMenu::ClickedButton() {
  this->hide();
  active_bank_adding_ex->setSizeIncrement(200, 0);
  active_bank_adding_ex->show();
}

void BankMenu::MenuActivated(int index) {
  active_bank_ex = new BankInterface(banks_array[index]);
  active_bank_ex->show();
  active_bank_ex->setSizeIncrement(120, 0);
}