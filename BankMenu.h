#include <QWidget>

#include <QPushButton>
#include <QPixmap>
#include <QVBoxLayout>
#include <QComboBox>
#include <QMenu>
#include <QAction>
#include <QLabel>
#include <QDialog>
#include <QSize>

#include <vector>

#include <Client.h>

#pragma once

class BankMenu : public QWidget {
Q_OBJECT

public:
    BankMenu(QWidget *parent);
    ~BankMenu();

    void active_bank_adding_finished(std::string&);

private:
    QComboBox* bank_menu;
    QPushButton* create_bank;
    QLabel* select_bank;

    std::vector<Bank*> banks_array;

    QVBoxLayout* layout_bank;

    QWidget* active_bank_ex;
    QWidget* active_bank_adding_ex;


public slots:
    void ClickedButton();
    void MenuActivated(int);
};