#include "AddBankForm.h"
#include "BankMenu.h"
#include "BankInterface.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);

  QTranslator translator;
  const QStringList uiLanguages = QLocale::system().uiLanguages();
  for (const QString &locale : uiLanguages) {
    const QString baseName = "try3_" + QLocale(locale).name();
    if (translator.load(":/i18n/" + baseName)) {
      app.installTranslator(&translator);
      break;
    }
  }
  std::vector<Bank*> banks_array;
  BankMenu* main_widget = new BankMenu(&banks_array, nullptr);

  main_widget->setSizeIncrement(110, 30);
  main_widget->show();
  return app.exec();
}