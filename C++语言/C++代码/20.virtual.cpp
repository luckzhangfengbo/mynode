/*************************************************************************
	> File Name: 20.virtual.cpp
	> Author:fangsong
	> Mail: fangsong517@gmail.com
	> Created Time: 2020年08月01日 星期六 15时51分12秒
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

class Animal{
public: 
    virtual void run() {
        cout << "I don't hnow how to run" << endl;
    }
};

class Cat : public Animal {
public :
    void run() override {
        cout << "I can run with four legs" << endl;
    }
};

class Dog : public Animal {
public :
    void run() override {
        cout << "I can run with four legs,yao~ yao~ yao~" << endl;
    }
};

class Bat : public Animal {
public :
    void run() override {
        cout << "I can fly" << endl;
    }
};


class A {
public :
    A() = default;
    A(string s) {
        cout << "param constructor" << endl;
    }
    A(const A &a) {
        cout << "copy constructor" << endl;
    }
    int x;
    virtual void say(int x) {
        cout << this << endl;
        cout << "class A : I can say, x = "<< x <<endl;
    }
};

typedef void (*func)(void *, int);

A retA() {
    A temp_a("hello world");
    return temp_a;
}


class Base{
    public :
    Base() {
        cout << "Base constructor" << endl;
        this->x = new int;
    }
    virtual ~Base() {
        cout << "Base destructor" << endl;
        delete[] this->x;
    }
    private:
    int *x;
};

class Base_A : public Base {
    public :
    Base_A() {
        cout << "Base_A constructor" << endl;
        this->y = new int;
    }
    ~Base_A() {
        cout << "Base_A destructor" << endl;
        delete this->y;
    }
    private:
    int *y;
};

int main() {
    Base *ba = new Base_A();
    delete ba;



    cout << sizeof(A) << endl;
    A temp_a, temp_b;
    temp_a.x = 9973;
    temp_b.x = 10000;
    temp_a.say(67);
    A temp_c = retA();
    ((func **)(&temp_a))[0][0](&temp_b, 6);
    srand(time(0));
    Cat a;
    Animal &b = a;
    Animal *c[10];
    cout << sizeof(Cat) << endl;

    for(int i = 0; i < 10; i++) {
        int op = rand() % 3;
        switch(op) {
            case 0:c[i] = new Cat();break;
            case 1:c[i] = new Dog();break;
            case 2:c[i] = new Bat();break;
        }
    }
    for(int i = 0; i < 10; i++) {
        c[i]->run();
    }
    return 0;
}
