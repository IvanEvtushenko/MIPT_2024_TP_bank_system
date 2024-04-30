#include "FirstWindow.h"
#include "AddBankWindow.h"
#include "SecondWindow.h"
#include <string>

Widget::Widget(std::vector<Bank*>* banks_array, QWidget* active_bank, QWidget* parent): banks_array(banks_array), active_bank_adding_ex(active_bank), QWidget(parent) {
  create_bank = new QPushButton("Cоздать банк");
  select_bank = new QLabel("Выберете банк для дальнейших действий");
  bank_menu = new QComboBox(this);

  layout_bank = new QVBoxLayout(this);
  layout_bank->addWidget(create_bank);
  layout_bank->addWidget(select_bank);
  layout_bank->addWidget(bank_menu);

  connect(create_bank, &QPushButton::clicked, this, &Widget::ClickedButton);
  connect(bank_menu, &QComboBox::activated, this, &Widget::MenuActivated);
}

Widget::~Widget() = default;


void Widget::active_bank_adding_finished(std::string& name) {
  bank_menu->addItem(QString::fromStdString(name));
  active_bank_adding_ex->hide();
  this->show();
}

void Widget::ClickedButton() {
  this->hide();
  active_bank_adding_ex->show();
  active_bank_adding_ex->setSizeIncrement(200, 0);
}

void Widget::MenuActivated(int index) {
  // Создаём новое окно и передаём туда выбранный пользователем банк
  active_bank_ex = new BankInterface((*banks_array)[index]);
  active_bank_ex->show();
  active_bank_ex->setSizeIncrement(120, 0);
}