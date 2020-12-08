/*************************************************************************
	> File Name: 8.class.cpp
	> Author:fangsong
	> Mail: 2035756541@qq.com
	> Created Time: 2020年07月25日 星期六 16时20分24秒
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

class People{
    friend int main();
    int x, y;
public :
    void set(int x);
    void say();
};

struct People2{
    int x, y;
};

void People::set(int x) {
    cout << "set functiona : " << this << endl;
    this->x = x;
    return;
}

void People::say() {
    cout << x << " " << y << endl;
    return;
}

int main() {
    People a;
    People2 b;
    a.y = 18432;
    cout << "a pbject : " << &a << endl;
    a.set(3);
    b.x = 4;
    a.say();
    cout << b.x << endl;
    return 0;
}
