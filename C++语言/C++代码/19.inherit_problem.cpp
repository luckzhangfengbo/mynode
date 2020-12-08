/*************************************************************************
	> File Name: 19.inherit_problem.cpp
	> Author:fangsong
	> Mail: fangsong517@gmail.com
	> Created Time: 2020年08月01日 星期六 15时17分49秒
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

struct A{
    int x;
};

struct B : virtual public A{
    void set(int x) {
        this->x = x;
        cout << "set :" << &this->x << endl;
    }
};


struct C : virtual public A{
    int get() {
        cout << "get : " << &this->x << endl;
        return this->x;
    }
};

struct D : public B, public C{};

int main() {
    D d;
    cout << sizeof(d) << endl;
    d.set(9973);
    cout << d.get() << endl;
    return 0;
}
