#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "QString"
#include "QStringListModel"
#include "QStringList"
#include "QListView"
#include "QTreeView"
#include "QTableView"
#include "QLabel"
#include "QPushButton"
#include "QInputDialog"
#include "QDateEdit"
#include "QGridLayout"
#include "QGroupBox"
#include "QVBoxLayout"
#include "QMessageBox"
#include "qDebug"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:

    //void menu();
    void registerSLOT();
    void loginSLOT();
    void msgAccept();

    void otvorenprozor();

private:
    Ui::Dialog *ui;

    QDialog *mainD;
    QDialog *registerD;
    QDialog *loginD;

    QPushButton *loginBtn, *registerBtn,  *rejectBtn, *backBtnR, *acceptBtnR;

    QLineEdit *nameR, *surnameR, *emailR, *passR, *passCR;
    QLabel *nameLabR, *surnameLabR, *emailLabR, *passLabR, *passCRLabR, *dateLabR;
    QDateEdit *dateDER;

    QLineEdit *emailL, *passL;
    QGridLayout *layoutM, *layoutR;
    QGroupBox *groupBoxM;

    QMessageBox *msgR;



    QLabel *picM, *picR;

};

#endif // DIALOG_H
