#include <QDialog>
#include <QLineEdit>
#include <QComboBox>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QFormLayout>
#include <QMessageBox>

#include "Client.h"

#pragma once

class BankInterface : public QWidget {
Q_OBJECT

private:
    Bank* active_bank;

public:
    explicit BankInterface(Bank*, QWidget *parent = nullptr);

    ~BankInterface();

    void active_client_adding_finished(std::string&, std::string&);


private:
    QLabel* label;
    QLineEdit* number;
    QLabel* empty;
    QPushButton* create_client;
    QLabel* select_client;
    QComboBox* client_menu;
    QPushButton* abort_transaction;

    QWidget* active_client_adding_ex;
    QWidget* active_client_ex;

    QFormLayout* layout_client;

public slots:
    void ClickedButton();
    void MenuActivated(int);
    void ClickedButton2();
};