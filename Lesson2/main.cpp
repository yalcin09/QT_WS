#include <QVector>
#include <QDebug>

#include <iostream>

//**************************** QVector ******************************
/* Constructor
 *
 * QVector(InputIterator first, InputIterator last)
 * QVector(std::initializer_list<T> args)
 * QVector(QVector<T> &&other)
 * QVector(const QVector<T> &other)
 * QVector(int size, const T &value)
 * QVector(int size)
 * QVector()
 */

int main()
{
    /*{
    // QVector tanımlama
    QVector<QString> vector1(5, "Yalçın");
    qDebug() << "vector1 : " << vector1;

    QVector<QString> vector2(10);
    qDebug() << "vector2 : " << vector2;

    QVector<int> vector3(10,2);
    qDebug() << "vector3 : " << vector3;

    QVector<int> vector4(std::move(vector3)); // vector3 için vector4'e taşı ve vector3 içini boşalt.
    qDebug() << "vector3 : " << vector3;
    qDebug() << "vector4 : " << vector4;

    // append : vector sonuna eleman ekler.
    QVector<int> vector5;
    for(int i=0; i<10; i++){
        vector5.append(i);
    }
    qDebug() << "vector5 : " << vector5;

    // move : vector içerisinde belirtiren değişkeni belirtiren değişkenin olduğu yere taşır.
    vector5.move(4,8);
    qDebug() << "move(4,8) uygulanmış vector5 : " << vector5;

    // at : vector içerisinde belirtiren indexteki değeri geri döndülür.
    for(int i=0; i<10; i++)
        vector5.append(i);

    for(int i=0; i<10; i++)
        qDebug() << vector5.at(i);

    for(int i=0; i<10; i++)
        qDebug() << vector5[i];

    // << : vector içerisine sondan eleman ekleme
    QVector<int> vector6;
    vector6 << 10 << 20 << 30;
    qDebug() << vector6;

    // random access iterator
    for(QVector<int>::iterator it = vector5.begin(); it != vector5.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;

    // Aralık uyumlu for döngüsü
    for(int x : vector5)
        std::cout << x << " ";
    std::cout << std::endl;

    // foreach yapısı
    foreach(int var, vector5)
        qDebug() << var;

    // push_back      : Eleman ekleme
    // begin ve end   : vector içeriğini düz bir şekilde okuma
    QVector<int> vector7;

    vector7.push_back(1);
    vector7.push_back(2);
    vector7.push_back(3);
    vector7.push_back(4);

    // rbegin ve rend : vector içeriğini tersten okuma
    // auto
    for(auto it = vector7.rbegin(); it != vector7.rend(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;

    // begin ve end   : vector içeriğini düz bir şekilde okuma
    for(auto it = vector7.begin(); it != vector7.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;

    // c++ yapısı ile reverse_iterator ile tersten okuma
    for(std::reverse_iterator<int*> it = vector7.rbegin(); it != vector7.rend(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;

    // QVector yapısı ile reverse_iterator yapısı
    for(QVector<int>::reverse_iterator it = vector7.rbegin(); it != vector7.rend(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;

    // cbegin ve cend :
    for(auto it = vector7.cbegin(); it != vector7.cend(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;

    // crbegin ve crend :
    for(auto it = vector7.crbegin(); it != vector7.crend(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
    return 0;
    }
    // empty   : vector'ün boş olması durumunda true değeri döner (qt)
    // isEmpty : vector'ün boş olması durumunda true değeri döner (c++)
    // clear   : vector içini tamamen silme
    {
    QVector<int> vector8;
    vector8 << 10 << 20 << 30 << 40 << 50 << 60 << 70;
    qDebug() << "vector8 : " << vector8;
    qDebug() << "empty : " << vector8.empty();
    qDebug() << "isEmpty : " << vector8.isEmpty();

    vector8.clear();
    qDebug() << "vector8.clear() : " << vector8;
    qDebug() << "empty : " << vector8.empty();
    qDebug() << "isEmpty : " << vector8.isEmpty();

    // erase : Belirli bir index'i veya aralığı silme
    QVector<int> vector9;
    vector9 << 10 << 20 << 30 << 40 << 50 << 60 << 70;
    qDebug() << "vector9 : " << vector9;

    vector9.erase(vector9.begin() + 3);
    qDebug() << "eraser ile bir eleman silme işelminden sonra vector9 : " << vector9;

    vector9.erase(vector9.begin() + 2, vector9.begin() + 4);
    qDebug() << "eraser ile belirli aralıktaki elemanları silme işelminden sonra vector9 : " << vector9;

    // first : baştaki değeri verir
    // front : baştaki değeri verir
    // last  : sondaki değeri verir
    QVector<int> vector10;
    vector10 << 10 << 20 << 30 << 40 << 50 << 60 << 70;
    qDebug() << "vector10 first : " << vector10.first();
    qDebug() << "vector10 front : " << vector10.front();
    qDebug() << "vector10 last : " << vector10.last();

    // indexOf     :
    // lastIndexOf :
    QVector<QString> vector11;
    vector11 << "a" << "b" << "c" << "d" << "c" << "f" << "c" << "e";
    qDebug() << "vector11 : " << vector11;
    qDebug() << "vector11.indexOf('c') : " << vector11.indexOf("c");
    qDebug() << "vector11.indexOf('c',1) : " << vector11.indexOf("c", 3);
    qDebug() << "vector11.indexOf('z') : " << vector11.indexOf("z");
    qDebug() << "vector11.lastIndexOf('c') : " << vector11.lastIndexOf("c");
    qDebug() << "vector11.lastIndexOf('c',1) : " << vector11.lastIndexOf("c",1);

    // removeAt : Belirtiren index'teki elemanı silme
    QVector<QString> vector12;
    vector12 << "a" << "b" << "c" << "d" << "c" << "f" << "c" << "e";
    qDebug() << "vector12 : " << vector12;
    vector12.removeAt(2);
    qDebug() << "removeAt vector12 : " << vector12;

    // mid : vektör içerisinden belirtiren parçaı almamısı sağlar
    QVector<int> vect1, result1, result2;
    for(int i=0; i<10; i++)
        vect1.append(i);
    
    result1 = vect1.mid(3,4);
    qDebug() << result1;

    result2 = vect1.mid(3,-1);
    qDebug() << result2;

    result2 = vect1.mid(3);
    qDebug() << result2;

    result2 = vect1.mid(3, 0);
    qDebug() << result2;
    }*/

    {
    // prepend :
    QVector<QString> vect1;
    vect1.prepend("one");
    vect1.prepend("two");
    vect1.prepend("three");
    qDebug() << "prepend : " << vect1;

    // append :
    QVector<QString> vect2;
    vect2.append("one");
    vect2.append("two");
    vect2.append("three");
    qDebug() << "append" << vect2;

    // insert :
    QVector<QString> vect3;
    vect3 << "elma" << "kiraz" << "karpuz";
    vect3.insert(3,"Kivi");
    vect3.insert(1,"kavun");
    qDebug() << "insert" << vect3;

    // back : STL fonksiyonu olarak ilk değeri referans olarak döndürür
    // count : Eleman sayısını döner
    // last : İlk değeri referans olarak döner
    qDebug() << "last => Vektör son elemanı : " << vect2.last();
    qDebug() << "back => Vector referan döner : " << vect2.back();
    qDebug() << "count => Vector eleman sayısı : " << vect2.count();


    // data : Vectörün başlangıç adresini döndürür
    QVector<int> vect4(10);
    int *data = vect4.data();
    for(int i=0; i<10; i++){
        data[i] = 2*i;
    }

    for(int i=0; i<10; i++)
        std::cout << data[i] << "\t";
    std::cout << std::endl;

    for(int i=0; i<10; i++)
        std::cout << vect4[i] << "\t";
    std::cout << std::endl;

    qDebug() << "********************************************";
    // fill :
    QVector<QString> vect5(5);
    vect5.fill("Yalçın");
    qDebug() << vect5;

    vect5.fill("Olgaç", 7);
    qDebug() << vect5;

    //fromList : List => vector yapma
    QStringList list;
    list << "Yalçın" << "Mehmet" << "Selçuk";
    qDebug() << list;

    QVector<QString> vect6;
    vect6 = QVector<QString>::fromList(list);
    qDebug() << vect6;


    }
    return 0;
}
