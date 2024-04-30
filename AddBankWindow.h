#include <QLineEdit>
#include <QGroupBox>
#include <QLabel>
#include <QFormLayout>
#include <QPushButton>
#include <QDialog>
#include <QMdiSubWindow>
#include "FirstWindow.h"

#include "Client.h"
#pragma once

class AddBankWindow : public QWidget {
Q_OBJECT

public:
    explicit AddBankWindow(std::vector<Bank*>*);
    ~AddBankWindow();

private:
    void closeEvent(QCloseEvent *event) override {
      static_cast<AddBankWindow*>(this)->parent_link->show();
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
    Widget* parent_link;
    QPushButton* is_done;

public slots:
    void ClickedButton();
};