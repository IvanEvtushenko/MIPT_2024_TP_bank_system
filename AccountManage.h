#include <QDialog>
#include <QLineEdit>
#include <QComboBox>
#include <QFormLayout>
#include <QPushButton>
#include <QLabel>

#include "Client.h"

#pragma once

class AccountManage : public QWidget {
Q_OBJECT

private:
    Bank* active_bank;
    Bank::Client* active_client;

public:
    explicit AccountManage(Bank*, Bank::Client*);

    ~AccountManage();

    void active_trans_adding_finished();

//    void active_tr_adding_finished(std::string&, std::string&);
private:
    QLabel* label;
    QLabel* label_debt;
    QLabel* label_credit;
    QLabel* label_dep;
    QPushButton* debt;
    QPushButton* credit;
    QPushButton* dep;

    QPushButton* create_transaction;
    QWidget* active_transaction_adding;

    QFormLayout* layout_lines;

public slots:
    void MakeDebtAccount();
    void MakeCreditAccount();
    void MakeDepAccount();
    void AddTransaction();
};