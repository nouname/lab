/** Модуль автоматической авторизации;
  * только для тестирования.
  */

#include <QApplication>
#include <QFile>
#include <stdlib.h>
#include "lib/api.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    VK::Client api;
    if (api.auth(string(getenv("LOGIN")), string(getenv("PASS")))){
      QFile f("data");
      f.open(QFile::WriteOnly);
      f.write(api.access_token().c_str());
      f.close();
    }
    return 0;
}
