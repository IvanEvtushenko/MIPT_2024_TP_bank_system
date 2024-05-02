#include <QLineEdit>
#include <QGroupBox>
#include <QLabel>
#include <QFormLayout>
#include <QPushButton>
#include <QComboBox>
#include <QMdiSubWindow>
#include <QMessageBox>

#include "AccountManage.h"

#include "Client.h"
#pragma once

class AddingTransaction: public QWidget {
Q_OBJECT

public:
    explicit AddingTransaction(Bank*, Bank::Client*, AccountManage*);
    ~AddingTransaction();

private:
    void closeEvent(QCloseEvent *event) override {
      this->parent_link->show();
      acceptDrops();
    }

    Bank* active_bank;
    Bank::Client* active_client;

    std::vector<Bank*>* banks_array;

    QLabel* label_client_name;

    QLabel* acc_types_label;
    QLabel* trans_types_label;
    QLabel* amount_label;

    QFormLayout* layout_form;

    QComboBox* acc_types;
    int acc_types_condition = 0;
    QComboBox* trans_types;
    int trans_types_condition = 0;
    QLineEdit* amount;

    AccountManage* parent_link;
    QPushButton* is_done;

public slots:
    void ClickedButton();
    void AccTypesMenuActivated(int);
    void TransTypesMenuActivated(int);
};