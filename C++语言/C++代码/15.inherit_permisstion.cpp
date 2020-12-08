/*************************************************************************
	> File Name: 15.inherit_permisstion.cpp
	> Author:fangsong
	> Mail: fangsong517@gmail.com
	> Created Time: 2020年07月28日 星期二 18时53分22秒
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

class Animal {
public :
    Animal(){}
    Animal(string name, int age) : __name(name), age(age) {}
    void say() {
        cout << "my name is " << __name  << ", my age is " << age << endl;
    }

protected:
    string __name;


private:
    int age;
};


class Cat : public Animal{
public :
    Cat() = delete;
    Cat(string name, int age) : Animal(name, age){}
};

class Bat : protected Animal{
public: 
    Bat() = delete;
    Bat(string name, int age) : Animal(name, age){}
    void say() {
        this->Animal::say();
        cout << "class Bat : " << __name << endl;
        //cout << "class age : " << age <<endl; 不能访问
    }
};


int main() {
    Cat a("kitty", 29);
    a.say();
    Bat b("fsong", 16384);
    b.say();
    return 0;
}
