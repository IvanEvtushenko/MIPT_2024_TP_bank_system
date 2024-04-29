#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QComboBox>
#include <QVBoxLayout>
#include <QPushButton>
#include "Client.h"

class Dialog : public QDialog {
Q_OBJECT

private:
    Bank* active_bank;

public:
    explicit Dialog(Bank*, QDialog *parent = nullptr);
    ~Dialog();


private:
    QPushButton* create_client;
    QLineEdit select_client;
    QComboBox* client_menu;
    QPushButton* abort_transaction;

    QVBoxLayout* layout_client;

    QDialog* active_client_ex{};

public slots:
    void ClickedButton();
    void MenuActivated(int);
    void ClickedButton2();
};
#endif // DIALOG_H