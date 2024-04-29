#ifndef WIDGET_H
#define WIDGET_H

#include <QMainWindow>

#include <QPushButton>
#include <QPixmap>
#include <QVBoxLayout>
#include <QComboBox>
#include <QMenu>
#include <QAction>
#include <QLineEdit>
#include <QDialog>
#include <QComboBox>
#include <QSize>
#include "Client.h"

//#include "AddBankWindow.h"
#include "oldDialog.h"


class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QPushButton* create_bank;
    QLineEdit select_bank;
    QComboBox* bank_menu;
    std::vector<Bank*> banks_array;

    QVBoxLayout* layout_bank;

//    QDialog* adding_bank_ex;
    QWidget* active_bank_ex;

public slots:
    void ClickedButton();
    void MenuActivated(int);
};
#endif // WIDGET_H
