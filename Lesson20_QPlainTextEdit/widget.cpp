#include "widget.h"
#include "ui_widget.h"

#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    blockCount = 0;

    ui->plainTextEdit->setPlaceholderText("This is a QPlainTextEdit");
    //ui->plainTextEdit->setUndoRedoEnabled(false);                      // false olursa ileri geri alamayız.


    connect(ui->selectAll, &QPushButton::clicked, [=](){
       ui->plainTextEdit->selectAll();
    });

    connect(ui->Copy, &QPushButton::clicked, [=](){
       ui->plainTextEdit->copy();
    });

    connect(ui->Paste, &QPushButton::clicked, [=](){
       ui->plainTextEdit->paste();
    });

    connect(ui->Cut, &QPushButton::clicked, [=](){
       ui->plainTextEdit->cut();
    });

    //*************************************************************
    connect(ui->Undo, &QPushButton::clicked, [=](){
       ui->plainTextEdit->undo();
    });

    connect(ui->Redo, &QPushButton::clicked, [=](){
       ui->plainTextEdit->redo();
    });

    connect(ui->Append, &QPushButton::clicked, [=](){
       ui->plainTextEdit->appendPlainText("Yalçın");
    });

    connect(ui->plainTextEdit, &QPlainTextEdit::blockCountChanged, [=](){
       qDebug() << "blockCount : " << ui->plainTextEdit->blockCount();
    });

    connect(ui->blockCountA, &QPushButton::clicked, [=](){
       ui->plainTextEdit->setMaximumBlockCount(++blockCount);
    });

    connect(ui->blockCountE, &QPushButton::clicked, [=](){
       ui->plainTextEdit->setMaximumBlockCount(--blockCount);
    });

    connect(ui->OverWriteMode, &QPushButton::clicked, [=](){
       if(ui->plainTextEdit->overwriteMode()){
           ui->OverWriteMode->setText("OverWriteMode Enable");
           ui->plainTextEdit->setOverwriteMode(false);
       }else{
           ui->OverWriteMode->setText("OverWriteMode Disable");
           ui->plainTextEdit->setOverwriteMode(true);
       }
    });
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    // Yazma izni verme yada vermeme
    if(ui->plainTextEdit->isReadOnly()){
        ui->plainTextEdit->setReadOnly(false);
        ui->pushButton->setText("Enable");
    }else{
        ui->plainTextEdit->setReadOnly(true);
        ui->pushButton->setText("Disable");
    }
}

