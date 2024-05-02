#include <QLineEdit>
#include <QGroupBox>
#include <QLabel>
#include <QFormLayout>
#include <QPushButton>
#include <QWidget>
#include <QMdiSubWindow>

#include "BankInterface.h"

#include "Client.h"
#include "Account.h"

#pragma once

class AddClient : public QWidget {
Q_OBJECT

public:
    explicit AddClient(Bank*, BankInterface*);
    ~AddClient();


private:
    void closeEvent(QCloseEvent *event) override {
      static_cast<AddClient*>(this)->parent_link->show();
      acceptDrops();
    }

    Bank* active_bank;

    QGroupBox* main_group;

    QLabel* label_client_name;
    QLabel* label_client_surname;
    QLabel* label_client_address;
    QLabel* label_client_passport;

    QLineEdit* client_name;
    QLineEdit* client_surname;
    QLineEdit* client_address;
    QLineEdit* client_passport;

    QFormLayout* layout_lines;

public:
    BankInterface* parent_link= nullptr;
    QPushButton* is_done;

public slots:
    void ClickedButton();
};