#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    registerD = new QDialog;
    loginD = new QDialog(this);

    registerBtn = new QPushButton(this);
    loginBtn = new QPushButton(this);
    rejectBtn = new QPushButton(this);

    picM = new QLabel(this);

    layoutM = new QGridLayout(this);

//------------------------------------------------------------------------------------
//                                          REGISTER
//------------------------------------------------------------------------------------

    nameR = new QLineEdit(registerD);
    surnameR = new QLineEdit(registerD);

    emailR = new QLineEdit(registerD);
    passR = new QLineEdit(registerD);
    passCR = new QLineEdit(registerD);

    nameLabR = new QLabel(registerD);
    surnameLabR = new QLabel(registerD);
    dateLabR = new QLabel(registerD);
    emailLabR = new QLabel(registerD);
    passLabR = new QLabel(registerD);
    passCRLabR = new QLabel(registerD);

    backBtnR = new QPushButton(registerD);
    acceptBtnR = new QPushButton(registerD);

    dateDER = new QDateEdit(registerD);

    msgR = new QMessageBox(registerD);

    picR = new QLabel(registerD);
    layoutR = new QGridLayout(registerD);

//------------------------------------------------------------------------------------
//                                          LOGIN
//------------------------------------------------------------------------------------

    emailL = new QLineEdit(loginD);
    passL = new QLineEdit(loginD);

    emailLabL = new QLabel(loginD);
    passLabL = new QLabel(loginD);

    backBtnL = new QPushButton(loginD);
    acceptBtnL = new QPushButton(loginD);

    msgL = new QMessageBox(loginD);

    picL = new QLabel(loginD);
    layoutL = new QGridLayout(loginD);


//====================================================================================
//                                          DIALOG (MENU)
//====================================================================================

    this->setMaximumSize(500,550);

    //Dodavanje buttona
    loginBtn->setText("Login");
    layoutM->addWidget(loginBtn,2,1,1,1);
    QObject::connect(loginBtn, SIGNAL(clicked()),this, SLOT(loginSLOT()));

    registerBtn->setText("Register");
    layoutM->addWidget(registerBtn,3,1,1,1);
    QObject::connect(registerBtn, SIGNAL(clicked()),this, SLOT(registerSLOT()));

    rejectBtn->setText("Exit");
    layoutM->addWidget(rejectBtn,4,1,1,1);

    //Konektovanje buttona sa prozorom
    connect(registerBtn,QPushButton::clicked,this,&Dialog::otvorenprozor);
    connect(loginBtn,QPushButton::clicked,this,&Dialog::otvorenprozor);
    connect(rejectBtn,QPushButton::clicked,this,&Dialog::close);


    QPixmap mypixM (":/images/logo2.png");
    mypixM = mypixM.scaled(200, 200, Qt::KeepAspectRatio);
    picM->setPixmap(mypixM);
    layoutM->addWidget(picM,0,1,1,1);

    QSpacerItem *itemLM = new QSpacerItem(30,30, QSizePolicy::Expanding, QSizePolicy::Fixed);
    QSpacerItem *itemRM = new QSpacerItem(30,30, QSizePolicy::Expanding, QSizePolicy::Fixed);
    QSpacerItem *itemDM = new QSpacerItem(30,30, QSizePolicy::Expanding, QSizePolicy::Fixed);
    layoutM->addItem(itemLM,0,0,1,1);
    layoutM->addItem(itemRM,0,2,1,1);
    layoutM->addItem(itemDM,8,1,1,1);
    this->setLayout(layoutM);



//====================================================================================
//                                          REGISTER
//====================================================================================

    QSpacerItem *itemLR = new QSpacerItem(30,30, QSizePolicy::Expanding, QSizePolicy::Fixed);
    QSpacerItem *itemRR = new QSpacerItem(30,30, QSizePolicy::Expanding, QSizePolicy::Fixed);
    QSpacerItem *itemDR = new QSpacerItem(30,30, QSizePolicy::Expanding, QSizePolicy::Fixed);
    QSpacerItem *itemMidR = new QSpacerItem(30,30, QSizePolicy::Expanding, QSizePolicy::Fixed);
    QSpacerItem *itemMidR2 = new QSpacerItem(30,30, QSizePolicy::Expanding, QSizePolicy::Fixed);
    layoutR->addItem(itemRR,0,2,1,1);
    layoutR->addItem(itemLR,0,0,1,1);
    layoutR->addItem(itemMidR,5,1,1,1);
    layoutR->addItem(itemDR,18,1,1,1);

    QPixmap mypixR (":/images/logo2.png");
    mypixR = mypixR.scaled(200, 200, Qt::KeepAspectRatio);
    picR->setPixmap(mypixR);

    layoutR->addWidget(picR,0,1,1,1);
    layoutR->addWidget(nameR,2,1,1,1);
    layoutR->addWidget(surnameR,4,1,1,1);
    layoutR->addWidget(emailR,9,1,1,1);
    layoutR->addWidget(passR,11,1,1,1);
    layoutR->addWidget(passCR,14,1,1,1);

    passR->setEchoMode(QLineEdit::Password);
    passCR->setEchoMode(QLineEdit::Password);


    dateDER->setCalendarPopup(true);
    layoutR->addWidget(dateDER,7,1,1,1);

    //Labels
    nameLabR->setText("Name:");
    nameLabR->setStyleSheet("font-family: georgia; color: white");
    layoutR->addWidget(nameLabR,1,1,1,1);

    surnameLabR->setText("Surname:");
    surnameLabR->setStyleSheet("font-family: georgia; color: white");
    layoutR->addWidget(surnameLabR,3,1,1,1);

    dateLabR->setText("Date of birth:");
    dateLabR->setStyleSheet("font-family: georgia; color: white");
    layoutR->addWidget(dateLabR,6,1,1,1);

    emailLabR->setText("E-mail:");
    emailLabR->setStyleSheet("font-family: georgia; color: white");
    layoutR->addWidget(emailLabR,8,1,1,1);

    passLabR->setText("Password:");
    passLabR->setStyleSheet("font-family: georgia; color: white");
    layoutR->addWidget(passLabR,10,1,1,1);

    passCRLabR->setText("Confirm password:");
    passCRLabR->setStyleSheet("font-family: georgia; color: white");
    layoutR->addWidget(passCRLabR,12,1,1,1);

    layoutR->addWidget(acceptBtnR,16,0,1,1);
    layoutR->addItem(itemMidR2,16,1,1,1);
    layoutR->addWidget(backBtnR,16,2,1,1);

    registerD->setLayout(layoutR);

    //Buttons
    acceptBtnR->setText("Confirm");
    QObject::connect(acceptBtnR, SIGNAL(clicked()),this, SLOT(msgAccept()));

    backBtnR->setText("Back");
    connect(backBtnR,QPushButton::clicked,this,&QDialog::open);


    if(passR->text() == passCR->text()){
        qDebug()<< "True";
    }
    else{
        qDebug()<<"False";
    }

    //====================================================================================
    //                                          LOGIN
    //====================================================================================

        QSpacerItem *itemLL = new QSpacerItem(30,30, QSizePolicy::Expanding, QSizePolicy::Fixed);
        QSpacerItem *itemRL = new QSpacerItem(30,30, QSizePolicy::Expanding, QSizePolicy::Fixed);
        QSpacerItem *itemDL = new QSpacerItem(30,30, QSizePolicy::Expanding, QSizePolicy::Fixed);
        QSpacerItem *itemMidL = new QSpacerItem(30,30, QSizePolicy::Expanding, QSizePolicy::Fixed);
        QSpacerItem *itemMidL2 = new QSpacerItem(30,30, QSizePolicy::Expanding, QSizePolicy::Fixed);
        layoutL->addItem(itemRL,0,2,1,1);
        layoutL->addItem(itemLL,0,0,1,1);
        layoutL->addItem(itemMidL,3,1,1,1);
        layoutL->addItem(itemDL,8,1,1,1);

        QPixmap mypixL (":/images/logo2.png");
        mypixL = mypixL.scaled(200, 200, Qt::KeepAspectRatio);
        picL->setPixmap(mypixL);

        layoutL->addWidget(picL,0,1,1,1);
        layoutL->addWidget(emailL,2,1,1,1);
        layoutL->addWidget(passL,5,1,1,1);

        passL->setEchoMode(QLineEdit::Password);

        //Labels
        emailLabL->setText("E-mail:");
        emailLabL->setStyleSheet("font-family: georgia; color: white");
        layoutL->addWidget(emailLabL,1,1,1,1);

        passLabL->setText("Password:");
        passLabL->setStyleSheet("font-family: georgia; color: white");
        layoutL->addWidget(passLabL,4,1,1,1);

        layoutL->addWidget(acceptBtnL,7,0,1,1);
        layoutL->addItem(itemMidL2,7,1,1,1);
        layoutL->addWidget(backBtnL,7,2,1,1);

        loginD->setLayout(layoutL);

        //Buttons
        acceptBtnL->setText("Confirm");
        QObject::connect(acceptBtnL, SIGNAL(clicked()),this, SLOT(msgAcceptL()));

        backBtnL->setText("Back");
        connect(backBtnL,QPushButton::clicked,this,&QDialog::open);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::loginSLOT(){

    loginD->setGeometry(710,240,500,550);
    loginD->setMaximumSize(500,620);
    loginD->setWindowTitle("Login");
}

void Dialog::registerSLOT(){

    registerD->setGeometry(710,240,500,620);
    registerD->setMaximumSize(500,620);
    registerD->setWindowTitle("Register");
}

void Dialog::msgAcceptR(){

    msgR->information(registerD, "Register successful",
                      "<FONT COLOR='white'>You've been successfully registered !\n</FONT>",
                      QMessageBox::Escape | registerD->close());
    msgR->setFixedSize(500,200);
}

void Dialog::msgAcceptL(){

    msgR->information(loginD, "Register successful",
                      "<FONT COLOR='white'>You've been successfully logged !\n</FONT>",
                      QMessageBox::Escape | loginD->close());
    msgR->setFixedSize(500,200);
}


void Dialog::otvorenprozor () {

QPushButton *button = qobject_cast<QPushButton*>(sender());

    if(button->text()=="Login") {
        QDialog::close();
        loginD->setVisible(true);
        }
    if(button->text()=="Register") {
        QDialog::close();
        registerD->setVisible(true);
        }
}
