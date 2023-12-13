#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class QLineEdit;
class QPushButton;

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
    void testEditTextChangedHandler(const QString &str);
    void pushButtonOkClickedHandler();

private:
    Ui::Widget *ui;
    QLineEdit *m_lineEditFirtName;
    QLineEdit *m_lineEditLastName;
    QLineEdit *m_lineEditCountry;
    QLineEdit *m_lineEditBirthDay;
    QLineEdit *m_lineEditPassword;

    QPushButton *m_PushButtonOk;
    QPushButton *m_PushButtonCancel;

    void initUI();
};
#endif // WIDGET_H
