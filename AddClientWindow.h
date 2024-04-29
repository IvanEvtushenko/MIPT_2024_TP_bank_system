#include <QLineEdit>
#include <QGroupBox>
#include <QLabel>
#include <QFormLayout>
#include <QPushButton>
#include <QDialog>
#include <QMdiSubWindow>

#include "SecondWindow.h"

#include "Client.h"
#include "Account.h"

#pragma once

class AddClientWindow : public QDialog {
Q_OBJECT

public:
    explicit AddClientWindow(Bank*);
    ~AddClientWindow();


private:
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

    void RebindParent(BankInterface*);

public slots:
    void ClickedButton();
};