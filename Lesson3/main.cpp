#include <QSet>
#include <QMap>
#include <QDebug>


int main()
{
    /*
     * QSet => std::set
     * Hızlı aramalarda kullanılabilir.
     *
     */
    QSet<QString> set;
    set.insert("Orhan");
    set.insert("Mehmet");
    set.insert("Yalçın");

    set << "Hakan" << "Merve" << "Selin";

    qDebug() << set;
    qDebug() << "Count : " << set.count();

    QSet<QString> set1;
    set1.insert("Nuri");
    set1.insert("Hakkı");
    set1.insert("Ayşe");
    set1.insert("Okan");
    set1.insert("Gül");
    foreach(const QString &s, set1)
        qDebug() << s;

    set.swap(set1);
    foreach(const QString &s, set1)
        qDebug() << s;

    qDebug() << set.empty();
    qDebug() << set.isEmpty();

    /*
     * QMap
     *
     * Anahtar ve değer çiftleri saklarlar
     * Ve bir anahtarla ilişkili değeri hızlı aramayı sağlarlar
     *
     */

    QMap<QString, int> map;

    // Ekleme işlemleri iki tip ile yapılabilir
    // [] veya insert

    map["Orhan"] = 1;
    map["Mehmet"] = 2;
    map["Hakan"] = 3;

    map.insert("Gül", 4);
    map.insert("Ayşe", 5);

    qDebug() << map;

    int value;
    foreach(value, map.values()){
        qDebug() << value;
    }

    QString key;
    foreach(key, map.keys()){
        qDebug() << key;
    }

    int num1 = map["Mehmet"];
    int num2 = map["Gül"];

    qDebug() << num1;
    qDebug() << num2;

    map["Ozan"] = 6;
    int tempInt = 0;

    if(map.contains("Ozan"))
        tempInt = map.value("Ozan");

    qDebug() << tempInt;

    // Not : Eğer aynı anahtar ile bir değer eklersek bu değer geçerli fakat eski değer silinmiş olur.


    return 0;
}
