/*************************************************************************
	> File Name: 39.visitor.cpp
	> Author:fangsong
	> Mail: fangsong517@gmail.com
	> Created Time: 2020年08月20日 星期四 10时47分24秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<map>
#include<vector>
#include<set>
using namespace std;
/*
Animal::IVisitor
XXX:IVisitor
*/

class Cat;
class Dog;
class Mouse;
class Bat;

class Animal {
public :
    class IVisitor{
        public:
        virtual void visit(Cat *) = 0;
        virtual void visit(Dog *) = 0;
        virtual void visit(Mouse *) = 0;
        virtual void visit(Bat *) = 0;
    };
    virtual void Accept(IVisitor *) = 0;
    virtual ~Animal(){};
};

class Cat : public Animal{
    public:
    virtual void Accept(IVisitor *vis) {
        vis->visit(this);// this ---> Cat
    }
};

class Dog : public Animal{
    public:
    virtual void Accept(IVisitor *vis) {
        vis->visit(this);// this ---> Dog 
    }

};

class Mouse : public Animal{
    public:
    virtual void Accept(IVisitor *vis) {
        vis->visit(this);// this ---> Mouse
    }
    
};

class Bat : public Animal{
    public:
    virtual void Accept(IVisitor *vis) {
        vis->visit(this);// this ---> Bat
    }

};

class AnimalCout : public Animal::IVisitor{
public:
    virtual void visit(Cat *){
        cout << "this is a Cat" << endl;
    };
    virtual void visit(Dog *){
        cout << "this is a Dog" << endl;
    };
    virtual void visit(Mouse *){
        cout << "this is a Mouse" << endl;
    };
    virtual void visit(Bat *){
        cout << "this is a Bat" << endl;        
    };
};


class Count : public Animal::IVisitor{
public:
    Count() : val1(0), val2(0), val3(0), val4(0) {};
    virtual void visit(Cat *){
       val1++;
    }
    virtual void visit(Dog *){
       val2++;
    }
    virtual void visit(Mouse *){
       val3++;
    }
    virtual void visit(Bat *){
       val4++;
    }
    int val1, val2, val3, val4;
};

int main() {
    srand(time(0));
    Animal *arr[10];
    for(int i = 0;i < 10; i++) {
        switch(rand() % 3) {
            case 0: arr[i] = new Cat(); break;
            case 1: arr[i] = new Dog(); break;
            case 2: arr[i] = new Mouse(); break;
            case 3: arr[i] = new Bat(); break;
        }
    }
    AnimalCout vis;
    Count vis1;
    for(int i = 0; i < 10; i++) {
        arr[i]->Accept(&vis);
        arr[i]->Accept(&vis1);
    }
    cout << vis1.val1 << endl;
    cout << vis1.val2 << endl;
    cout << vis1.val3 << endl;
    cout << vis1.val4 << endl;
    return 0;
}
