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
    explicit AddBankWindow(std::vector<Bank*>*, QWidget *parent = nullptr);
    ~AddBankWindow();


private:
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
    Widget* parent_copy;
    QPushButton* is_done;

public slots:
    void ClickedButton2();
};