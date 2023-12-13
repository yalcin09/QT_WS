#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_comboBox_currentIndexChanged(int index);

    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_pushButtonCaptureValue_clicked();

    void on_pushButtonSetValue_clicked();

    void on_pushButtonGetValue_clicked();

    void on_pushButtonFindText_clicked();

    void on_pushButtonRemoveItem_clicked();

private:
    Ui::Widget *ui;

    void initComboBox();
};
#endif // WIDGET_H
