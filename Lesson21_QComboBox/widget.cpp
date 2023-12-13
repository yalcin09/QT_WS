#include "widget.h"
#include "ui_widget.h"

#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    initComboBox();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::initComboBox()
{
    ui->comboBox->addItem(QIcon(":/images/banana.jpg"), "Banana");
    ui->comboBox->addItem(QIcon(":/images/orange.jpg"), "Orange");
    ui->comboBox->addItem(QIcon(":/images/apple.jpg"), "Apple");
    ui->comboBox->addItem(QIcon(":/images/cherry.jpg"), "Cherry");

    ui->comboBox->setEditable(true);  // yeni eleman ekleme
    ui->comboBox->setInsertPolicy(QComboBox::InsertAtTop); // Eklenen elemanlar üst kıma yazılsın
    ui->comboBox->setDuplicatesEnabled(false); // eklenen elemanlar bir daha eklenmesin
    ui->comboBox->setMaxCount(8); // 8 adet ekleme sınırı

    ui->lineEditIndex->setText("0");

}


void Widget::on_comboBox_currentIndexChanged(int index)
{

}


void Widget::on_comboBox_currentTextChanged(const QString &arg1)
{
    qInfo() << "Current index text is : " << arg1;
}


void Widget::on_pushButtonCaptureValue_clicked()
{
    // comboBox seçili olan elemanın indeksini ve değerini alma
    qInfo() << "Current select item index is : " << ui->comboBox->currentIndex() <<
               " and text : " << ui->comboBox->currentText();
}


void Widget::on_pushButtonSetValue_clicked()
{
    int index = ui->lineEditIndex->text().toInt();

    if(index < ui->comboBox->count())
        ui->comboBox->setCurrentIndex(index);
    else
        qInfo() << "not fount index!!!";
}


void Widget::on_pushButtonGetValue_clicked()
{
    qInfo() << "ComboBox has : " << ui->comboBox->count() << " item";

    for(int i=0; i<ui->comboBox->count(); ++i)
        qInfo() << "ComboBox Index : " << i << " text : " << ui->comboBox->itemText(i);
}


void Widget::on_pushButtonFindText_clicked()
{
    QString sFindText = ui->lineEditFindText->text();
    int index = ui->comboBox->findText(sFindText);

    if(index >= 0 && index < ui->comboBox->count())
        qInfo() << "Found text : " << sFindText << " index : " << index;
    else
        qInfo() << "Not found: " << sFindText;
}


void Widget::on_pushButtonRemoveItem_clicked()
{
    ui->comboBox->removeItem(ui->comboBox->currentIndex());
}

