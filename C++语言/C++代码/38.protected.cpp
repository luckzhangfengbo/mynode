/*************************************************************************
	> File Name: 38.protected.cpp
	> Author:fangsong
	> Mail: fangsong517@gmail.com
	> Created Time: 2020年08月20日 星期四 09时35分37秒
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
        x = rand() % 10;
        cout << this << "init x value : " << x << endl;
    }
    protected:
    int x;
};
class C : public A {
    public :
    int z;
};
class B : public A {
    public :
    void say(B& b) {
        cout << &b <<" x value : "<< (static_cast<A &>(b)).x << endl;
    }
    //static_cast在编译期,无法确定原始类型, dynamic_cast是运行期的
    void say(C& b) {
        cout << &c <<" x value : "<< (static_cast<A &>(c)).x << endl;
    }
};
int main() {
    B b1, b2;
    b1.say(b2);
    return 0;
}
