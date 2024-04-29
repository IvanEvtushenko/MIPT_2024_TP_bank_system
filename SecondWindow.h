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
    explicit Dialog(Bank*, QWidget *parent = nullptr);

    ~Dialog();


private:
    QPushButton* create_client;
    QLineEdit select_client;
    QComboBox* client_menu;
    QPushButton* abort_transaction;

    QVBoxLayout* layout_client;

public slots:
    void ClickedButton();
    void MenuActivated(int);
    void ClickedButton2();
};