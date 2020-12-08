/*************************************************************************
	> File Name: 17.inherit_copy.cpp
	> Author:fangsong
	> Mail: fangsong517@gmail.com
	> Created Time: 2020年07月28日 星期二 20时45分08秒
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


class A {
public :
    A() {
        cout << "class A constuctor" << endl;
        this->x = 0x01020304;
    }
    A(const A &a) {
        cout << "class A copy constuctor : "<< this << endl;
    }
    int x;
};


class B : public A {
    /*头部存储父类相关的信息;
    * */
public :
    B() {
        this->y = 0x05060708;
        cout << "class B constuctor" << endl;
    }
    B(const B &b) : A(b) {
        cout <<  "class B copy constuctor : " << this << endl;
    }
    int y;
};

int main() {
    B b1;
    B b2(b1);
    const char *msg = (const char *)(&b1);
    for(int i = 0; i < sizeof(B); i++) {
        printf("%X", msg[i]);
    }
    
    return 0;
}
