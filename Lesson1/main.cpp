#include <QChar>
#include <QString>
#include <QDebug>

#include <iostream>
#include <string>

int main()
{

    {
        /* QChar sınıfı kullanımı */
        /*  QChar sınıfı kullanımı
        QChar(uchar ch)
        QChar(char ch)
        QChar(wchar_t ch)
        QChar(char16_t ch)
        QChar(QLatin1Char ch)
        QChar(QChar::SpecialCharacter ch)
        QChar(int code)
        QChar(uint code)
        QChar(short code)
        QChar(uchar cell, uchar row)
        QChar(ushort code)
        QChar()
        */

        // Karakter direk olarak eklenebilir.
        QChar c1('a');
        qDebug() << "c1 : " << c1;

        // ASCI kod değeri yazılarakta karakter eklebenilir.
        QChar c2(122);
        qDebug() << "c2 : " << c2;

        QChar c3('1');
        qDebug() << "c3 : " << c3;

        // Karakterin bir rakam mı? Olup olmadığını bildiren fonksiyon
        qDebug() << "c1 bir rakam mı? : " << c1.isNumber();
        qDebug() << "c2 bir rakam mı? : " << c2.isNumber();
        qDebug() << "c3 bir rakam mı? : " << c3.isNumber();

        // Tanımlanan QChar türünden değişkenin içinde bir karakter olup olmadığını bildiren fonksiyon
        // QChar cX();   -> Bu tarz tanımlama yapılamaz
        // QChar cX(''); -> Bu tarz tanımlama yapılamaz.
        QChar c4('D');
        QChar c5('\0');

        qDebug() << "c4 : " << c4.isNull();
        qDebug() << "c5 : " << c5.isNull();

        // Karakterlerin Büyük veya küçük olarak değiştilirmesi
        qDebug() << "c1 karakterinin >toUpper()< kullanarak büyük yapılması : " << c1.toUpper();
        qDebug() << "c4 karakterinin >toLower()< kullanarak küçük yapılması : " << c4.toLower();

        // Karakterin küçük mü büuük mü olduğunu bildiren fonlsiyonlar
        qDebug() << "c1 Büyük mü? : " << c1 << " " << c1.isUpper();
        qDebug() << "c4 Küçük Mü? : " << c4 << " " << c1.isLower();
    }

    qDebug() << "------------------------------------------------------------------";

    {

        /* QString Sınıfının kullanımı */
        /*
        QString(const QByteArray &ba)
        QString(const char *str)
        QString(QString &&other)
        QString(const QString &other)
        QString(QLatin1String str)
        QString(int size, QChar ch)
        QString(QChar ch)
        QString(const QChar *unicode, int size = -1)
        QString()
        */

        QString str1("Yalçın OLGAÇ");           // Constructor yapısı
        QString str2 = "Günün dersi : QString"; // Copy Assigment
        QString str3(10,'A');
        QString str4(10, QChar('B'));
        qDebug() << "str1 : " << str1;
        qDebug() << "str2 : " << str2;
        qDebug() << "str3 : " << str3;
        qDebug() << "str4 : " << str4;

        // isNull  : Değişken içerisinde herhangi bir şeyin olmamsı durumunda (QChar ch() şeklinde) True değeri döner.
        // isEmpty : Değişken içerisinde karakter yok ise (QString str() veya QString str("") şeklinde) True değeri döner.
        QString str5;
        QString str6("");
        QString str7("A");
        qDebug() << "(True) isNull ile str5 kontrol : " << str5.isNull();
        qDebug() << "(True) isEmpty ile str5 kontrol : " << str5.isEmpty();
        qDebug() << "(False) isNull ile str6 kontrol : " << str6.isNull();
        qDebug() << "(True) isEmpty ile str6 kontrol : " << str6.isEmpty();
        qDebug() << "(False) isNull ile str7 kontrol : " << str7.isNull();
        qDebug() << "(False) isEmpty ile str7 kontrol : " << str7.isEmpty();

        // insert : Belirtiren bir posizyona karakter ekleme
        QString str8("Merhaba");
        qDebug() << "str8 : " << str8;

        str8.insert(7," Dünya");
        qDebug() << "str8 insert ile : " << str8;

        QString str9("Heyyy");
        str9.insert(5, " "+str8);
        qDebug() << "str9 : " << str9;

        // Remove : Belirtiren fonksiyondan eleman çıkarma
        QString str10("Merhaba Dünya ve Yalçın");
        qDebug() << "Str10 : " << str10;

        str10.remove(7,9);
        qDebug() << "Remove işleminden sonra str10 : " << str10;

        // left  : Sol taraftan belirtiren karakter sayısı kadar karakter alma.
        // right : Sağ taraftan belirtiren karakter sayısı kadar karakter alma.
        QString str11 = "Merhaba";
        qDebug() << "str11 : " << str11;
        QString str12 = str11.left(3);
        qDebug() << "str12 : " << str12;
        QString str13(str11.right(4));
        qDebug() << "str13 : " << str13;

        // section : Belirtiren karakterden sonra belirtiren araklıktaki karakterleri alma
        QString str14;
        QString str15 = "forename,middlename,surname,phone";
        QString str16 = "/usr/local/bin/qt5";

        qDebug() << "str15 için str15.section('.',2,2) : " << str15.section(",",2,2);
        qDebug() << "str16 için str16.section('/',3,4) : " << str16.section("/",3,4);
        qDebug() << "str16 için str16.section('/',3,3) : " << str16.section("/",3,3);

        // replace : Yer değiştirme
        QString str17 = "Yalçın, Mehmet, ALi, Kadir";
        qDebug() << "str17 : " << str17;
        str17.replace(',',';');
        qDebug() << "replace işleminden sonra str17 : " << str17;

        // indexOf : String ve karakterin index'ini verir.
        QString str18("Merhaba Dünya ve Yalçın");
        int index;

        index = str18.indexOf("Dünya");
        qDebug() << index;

        // mid : Belirtiren pozisyondan iltibaren istenilen sayı kadar karakter alma.
        QString str19("2043368822761");
        QString str20;
        str20 = str19.mid(6,4);
        qDebug() << "str20 : " << str20;

        // rightJustified / leftJustified : String ifadeyi sağ / sol tarafa alarak belirtiren karakter sayısını
        // tamamlamak için eksik karakter yerine belirtiren karakter ile dordurma işlemi yapılır.
        QString str21("Elma");
        qDebug() << "str21 : " << str21;
        QString str22 = str21.leftJustified(10, '.');
        qDebug() << "str21 kullanılarak leftJustified() sonucu -> str22 : " << str22;
        QString str23 = str21.rightJustified(10, '.');
        qDebug() << "str21 kullanılarak rightJustified() sonucu -> str23 : " << str23;

        QString str24("Elma, Çilek ve Kiraz");
        qDebug() << "str24 : " << str24;
        QString str25 = str24.leftJustified(10, '.', true);
        qDebug() << "str24 kullanılarak leftJustified() sonucu -> str25 : " << str25;
        QString str26 = str24.rightJustified(10, '.', true);
        qDebug() << "str24 kullanılarak rightJustified() sonucu -> str26 : " << str26;

        // trimmed : String içerisindeki karakterlerini siler
        QString str27("Merhaba\r\n");
        qDebug() << "str27 : " << str27;
        QString str28 = str27.trimmed();
        qDebug() << "str27 trimmed() işleimi uygulandı : " << str28;

        // truncate : Belirtiren pozisyondan sonra kesme işlemi yapar.
        QString str29("Koca yaşlı şişko dünya");
        qDebug() << "str29 : " << str29;
        str29.truncate(10);
        qDebug() << "truncate(10) işleminden sonra str29 : " << str29;

        // repeated : Belirtiren string ifadeyi belirtiren sayıda ard arda yazar ve aynı değişkene aktarır.
        QString str30("Yalçın");
        QString str31 = (str30.repeated(5));
        qDebug() << "str31 : " << str31;

        // contains : String içinde string arama işlemi varsa True döner.
        QString str32("Elma, Çilek ve Kiraz");
        qDebug() << str32.contains("Kiraz", Qt::CaseInsensitive);

        // number static : Sayısal ifadeleri string ifadeye dönüştürme
        long a = 63;
        QString str33 = QString::number(a, 16); // a değişkenini 16'lık tabanda string ifadeye dönüştür.
        qDebug() << "a=63 to 16 => str33 : " << str33;
        QString str34 = QString::number(a,10);
        qDebug() << "a=63 to 10 => str34 : " << str34;
        QString str35 = QString::number(a,16).toUpper();
        qDebug() << "a=63 to 16 => .toUpper str33 : " << str35;

        // toInt, toLong, toDouble : String ifadeleri sayısal ifadelere dönüştürme
        QString str36("25.48");
        qDebug() << "str36 : " << str36;
        double str36todouble = str36.toDouble();
        qDebug() << "str36 to double : " << str36todouble;
        int str36toint = str36.toInt();
        qDebug() << "str36 to int : " << str36toint;

        QString str37("25");
        qDebug() << "str37 : " << str37;
        double str37todouble = str37.toDouble();
        qDebug() << "str37 to double : " << str37todouble;
        int str37toint = str37.toInt();
        qDebug() << "str37 to int : " << str37toint;

        // toStdString : QString türünü C++ String türüne dönüştürür.
        QString str38("Yalcin OLGAC");
        std::string cppStr;
        cppStr = str38.toStdString();
        std::cout << cppStr << std::endl;

        // toUpper ve toLower : Büyük harf ve küçük harf yapma
        qDebug() << "str38'in hepsini büyük half yapma : " << str38.toUpper();
        qDebug() << "str38'in hepsini küçük half yapma : " << str38.toLower();

        // compare : karşılaştırma yapma
        QString str39("ankara");
        QString str40("ankire");

        qDebug() << QString::compare(str39,str40);

        // append ve prepend : ekleme işlemi
        QString str41(" free");
        QString str42(" down");
        str41.append(str42);
        qDebug() << str41;

        QString str43(" free");
        QString str44(" down");
        str43.prepend(str44);
        qDebug() << str43;

        // split : string ifade içindeki yapıyı aralarındaki belirtiren karaktere göre list formatına dönüştürüyor.
        QString str45("Yalçın Orhan Veli Hakkı Kamil");
        QStringList list1 = str45.split(' ');
        foreach(QString item, list1){
            qDebug() << item;
        }
        qDebug("--------------------------------------------------");
        QStringListIterator i(list1);
        while(i.hasNext()){
            qDebug() << i.next();
        }
        qDebug("--------------------------------------------------");
        for(int count=0; count < list1.size(); count++){
            qDebug() << list1[count];
        }

        // arg : içindeki >> %n << yerini doldulur.
        int aa=1, bb=2;
        QString str46("aa = %1, bb = %2");
        qDebug() << str46;
        QString str47 = str46.arg(aa);
        qDebug() << str47;
        QString str48 = str46.arg(bb);
        qDebug() << str48;

        // Girdi alma
        QTextStream qStr(stdin);
        QString str49;

        str49 = qStr.readLine();
        qDebug() << "str : " << str49;
    }


    return 0;
}
