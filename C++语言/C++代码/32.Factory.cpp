/*************************************************************************
	> File Name: 32.Factory.cpp
	> Author:fangsong
	> Mail: fangsong517@gmail.com
	> Created Time: 2020年08月21日 星期五 11时12分08秒
 ************************************************************************/

#include <iostream>
#include <ctime>
using namespace std;

class ICar {
public :
    class IFactory {
    public :
        virtual ICar *crearte() = 0;
    };
    virtual void run() = 0;
protected:
    ICar() {}
    ~ICar() {}
};

class BenzCar : public ICar {
    BenzCar() {}
public :
    class Facory : public ICar::IFactory {
    public :
        virtual ICar *crearte() {
            return new BenzCar();
        }
    };
    virtual void run() {
        cout << "Benz run" << endl;
    }
};

class BmwCar : public ICar {
    BmwCar() {}
public :
    class Facory : public ICar::IFactory {
    public :
        virtual ICar *crearte() {
            return new BmwCar();
        }
    };
    virtual void run() {
        cout << "Bmw run" << endl;
    }
};

class AudiCar : public ICar {
    AudiCar() {}
public :
    class Facory : public ICar::IFactory {
    public :
        virtual ICar *crearte() {
            return new AudiCar();
        }
    };
    virtual void run() {
        cout << "Audi run" << endl;
    }
};

ICar::IFactory *fac[3] = {new BenzCar::Facory(), new AudiCar::Facory, new BmwCar::Facory()};

int main() {
    srand(time(0));
    ICar *cars[10];
    for (int i = 0; i < 10; i++) {
        cars[i] = fac[rand() % 3]->crearte();
    }
    for (int i = 0; i < 10; i++) {
        cars[i]->run();
    }
    return 0;
}
