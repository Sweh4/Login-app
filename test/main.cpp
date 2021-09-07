#include "dialog.h"
#include <QApplication>

QString styleSheet = "QDialog{\
                              background-color: rgb(71,85,94)\
                             }";

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyleSheet(styleSheet);
    Dialog w;
    w.show();

    return a.exec();
}
