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

class Widget : public QWidget {
Q_OBJECT

public:
    Widget(std::vector<Bank*>*, QWidget*, QWidget *parent = nullptr);
    ~Widget();

    void active_bank_adding_finished(std::string&);

protected:
    QComboBox* bank_menu;

private:
    QPushButton* create_bank;
    QLabel* select_bank;
    std::vector<Bank*>* banks_array;

    QVBoxLayout* layout_bank;

    QWidget* active_bank_ex;
    QWidget* active_bank_adding_ex;


public slots:
    void ClickedButton();
    void MenuActivated(int);
};