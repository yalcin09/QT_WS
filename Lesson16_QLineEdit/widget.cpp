#include "widget.h"
#include "ui_widget.h"

#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <QDebug>
#include <QFont>
#include <QString>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    setWindowTitle("QLineEdit Demo");
    resize(280,370);

    initUI();

    connect(m_PushButtonOk, &QPushButton::clicked, this, &Widget::pushButtonOkClickedHandler);
    connect(m_PushButtonOk, &QPushButton::clicked, m_lineEditBirthDay, &QLineEdit::clear);
    connect(m_PushButtonOk, &QPushButton::clicked, m_lineEditCountry, &QLineEdit::clear);
    connect(m_PushButtonOk, &QPushButton::clicked, m_lineEditFirtName, &QLineEdit::clear);
    connect(m_PushButtonOk, &QPushButton::clicked, m_lineEditLastName, &QLineEdit::clear);
    connect(m_PushButtonOk, &QPushButton::clicked, m_lineEditPassword, &QLineEdit::clear);


//    QObject::connect(m_lineEditFirtName, SIGNAL(textChanged(QString)),
//                     this, SLOT(testEditTextChangedHandler(QString)));

//    // İmleç pozisyonunu alma
//    connect(m_lineEditFirtName, &QLineEdit::cursorPositionChanged, [=](){
//       qDebug() << "Cursor position changed is : " << m_lineEditFirtName->cursorPosition();
//    });

//    // Enter basılınca işlem bitir.
//    connect(m_lineEditFirtName, &QLineEdit::editingFinished, [=](){
//       qDebug() << "Editing Finishing is : ";
//    });

//    // Enter basılınca geri dönüş al.
//    connect(m_lineEditFirtName, &QLineEdit::returnPressed, [=](){
//       qDebug() << " Return Pressed ";

//    // Karakter veya metni seçme sırasında dönüş alma
//    connect(m_lineEditFirtName, &QLineEdit::selectionChanged, [=](){
//      qDebug() << " selection Changed ";

//    // Her değişimde geri bildirim alma
//    connect(m_lineEditFirtName, &QLineEdit::textChanged, [=](){
//        qDebug() << "Text Changed : " << m_lineEditFirtName->text();

//    // Her değişimde geri bildirim alma
//      connect(m_lineEditFirtName, &QLineEdit::textEdited, [=](){
//          qDebug() << "Text Edited : " << m_lineEditFirtName->text();
//    });

}

Widget::~Widget()
{
    delete ui;
}

void Widget::testEditTextChangedHandler(const QString &str)
{
    qDebug() << str;
}

void Widget::pushButtonOkClickedHandler()
{
    /*
    QString firstLastName;
    firstLastName = QString("First-Last Name : %1 %2").arg(m_lineEditFirtName->text()).arg(m_lineEditLastName->text());
    qDebug() << firstLastName;
    */

    //m_lineEditFirtName->setCursorPosition(5);
    //m_lineEditFirtName->paste();

    QString firstName = m_lineEditFirtName->text();
    QString lastName = m_lineEditLastName->text();
    QString country = m_lineEditCountry->text();
    QString birthday = m_lineEditBirthDay->text();
    QString password = m_lineEditPassword->text();

    if(!firstName.isEmpty() && !lastName.isEmpty() && !country.isEmpty() && !birthday.isEmpty() && !password.isEmpty()){
        qDebug() << "First Name : " << firstName;
        qDebug() << "Last Name : " << lastName;
        qDebug() << "Country Name " << country;
        qDebug() << "Birthday : " << birthday;
        qDebug() << "Password : " << password;
    }else
        qDebug() << "Failed";
}

void Widget::initUI()
{
    m_lineEditFirtName = new QLineEdit("First Name", this);
    m_lineEditFirtName->move(10,10);
    m_lineEditFirtName->setMinimumSize(260,50);
    //m_lineEditFirtName->setMaxLength(10);                               // Maksimum 10 karakter
    //m_lineEditFirtName->setFont(QFont('Times', 15));                    // Yazı font ayarı
    //m_lineEditFirtName->setText("First Name");                          // Başlangıç metni
    //m_lineEditFirtName->setPlaceholderText("Please, Enter First Name"); // Bilgilendirme metni
    //m_lineEditFirtName->setReadOnly(true);                              // Sadece okuma yazma işlemi kapalı
    //m_lineEditFirtName->setClearButtonEnabled(true);                    // Temizleme ikonu




    m_lineEditLastName = new QLineEdit("Last Name", this);
    m_lineEditLastName->move(10,70);
    m_lineEditLastName->setMinimumSize(260,50);

    m_lineEditCountry = new QLineEdit("Country", this);
    m_lineEditCountry->move(10,130);
    m_lineEditCountry->setMinimumSize(260,50);

    m_lineEditBirthDay = new QLineEdit("Birthday", this);
    m_lineEditBirthDay->move(10,200);
    m_lineEditBirthDay->setMinimumSize(260,50);
    m_lineEditBirthDay->setInputMask("00/00/0000");

    m_lineEditPassword = new QLineEdit("Password", this);
    m_lineEditPassword->move(10,260);
    m_lineEditPassword->setMinimumSize(260,50);
    m_lineEditPassword->setEchoMode(QLineEdit::Password);

    m_PushButtonOk = new QPushButton("OK", this);
    m_PushButtonOk->move(10,320);
    m_PushButtonOk->setMinimumSize(125,40);

    m_PushButtonCancel = new QPushButton("Cancel", this);
    m_PushButtonCancel->move(145,320);
    m_PushButtonCancel->setMinimumSize(125,40);

}

