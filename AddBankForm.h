#include <QLineEdit>
#include <QGroupBox>
#include <QLabel>
#include <QFormLayout>
#include <QPushButton>
#include <QDialog>
#include <QMdiSubWindow>
#include "BankMenu.h"
#include <QMessageBox>

#include "Client.h"
#pragma once

class AddBank : public QWidget {
Q_OBJECT

public:
    explicit AddBank(std::vector<Bank*>*, BankMenu*);
    ~AddBank();

private:
    void closeEvent(QCloseEvent *event) override {
      parent_link->show();
      acceptDrops();
    }

    std::vector<Bank*>* banks_array;

    QGroupBox* main_group;

    QLabel* label_bank_name;
    QLabel* label_bank_commission;
    QLabel* label_bank_limit;
    QLabel* label_bank_time_limit;

    QLineEdit* bank_name;
    QLineEdit* bank_commission;
    QLineEdit* bank_limit;
    QLineEdit* bank_time_limit;

    QFormLayout* layout_lines;

public:
    BankMenu* parent_link;
    QPushButton* is_done;

public slots:
    void ClickedButton();
};