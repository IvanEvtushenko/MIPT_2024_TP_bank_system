#include "AddBankWindow.h"
#include "FirstWindow.h"
#include <QApplication>
#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);

  QTranslator translator;
  const QStringList uiLanguages = QLocale::system().uiLanguages();
  for (const QString &locale : uiLanguages) {
    const QString baseName = "try3_" + QLocale(locale).name();
    if (translator.load(":/i18n/" + baseName)) {
      a.installTranslator(&translator);
      break;
    }
  }
  std::vector<Bank*> banks_array;
  banks_array.push_back(new Bank("efr", 234, 324, 234));
  AddBankWindow add(&banks_array);
  Widget wid(&banks_array, &add);
  add.parent_copy = &wid;
  AddBankWindow* ab = &add;
  Widget* ba = &wid;

  wid.setSizeIncrement(110, 30);
  wid.show();
  return a.exec();
}
