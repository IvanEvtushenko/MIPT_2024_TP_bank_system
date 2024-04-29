#include "MainWindow.h"
#include <string>

MainWindow::MainWindow(QWidget* parent): QMainWindow(parent) {
  banks_array = std::vector<Bank*>();

  create_bank = new QPushButton("Cоздать банк");
  select_bank.setText("Выберете банк для дальнейших действий");
  select_bank.setReadOnly(true);
  bank_menu = new QComboBox(this);

  layout_bank = new QVBoxLayout(this);
  layout_bank->addWidget(create_bank);
  layout_bank->addWidget(&select_bank);
  layout_bank->addWidget(bank_menu);

  connect(create_bank, &QPushButton::clicked, this, &MainWindow::ClickedButton);
  connect(bank_menu, &QComboBox::activated, this, &MainWindow::MenuActivated);
}

MainWindow::~MainWindow() = default;


void MainWindow::ClickedButton() {
  qDebug("Создание банка начато успешно");
  // TODO форма для ручного добавления банка, пока заглушка
//  adding_bank_ex = new AddBankWindow(banks_array, nullptr);
  char bank_name_tmp[] = "Сбербанк";
  banks_array.push_back(new Bank(bank_name_tmp, 0, -20000, 10000));
  bank_menu->addItem(QString((banks_array[banks_array.size() - 1])->bank_name));
  // Обращение к банку будет по индексу добавленного в список элемента
}

void MainWindow::MenuActivated(int index) {
  // Создаём новое окно и передаём туда выбранный пользователем банк

  active_bank_ex = new Dialog(banks_array[index], this);
  active_bank_ex->setModal(true);
  active_bank_ex->setSizeIncrement(110, 30);
  active_bank_ex->exec();
}
