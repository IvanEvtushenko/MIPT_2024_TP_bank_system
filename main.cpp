#include "AddBankWindow.h"
#include "FirstWindow.h"
#include "SecondWindow.h"

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
  AddBankWindow add_bank(&banks_array);
  Widget main_widget(&banks_array, &add_bank);
  add_bank.parent_link = &main_widget;

  main_widget.setSizeIncrement(110, 30);
  main_widget.show();
  return app.exec();
}
