/*************************************************************************
	> File Name: 24.constexpr.cpp
	> Author:fangsong
	> Mail: fangsong517@gmail.com
	> Created Time: 2020年08月02日 星期日 18时56分40秒
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

constexpr int f(int x) {
    if(x == 1) return 1;
    return x * f(x - 1);
}

class A {
    public:
    constexpr A(int x,int y) : x(x), y(y) {}
    int x, y;
};

int main() {
    int n;
    cin >> n;
    cout << f(n) << endl;
    constexpr int m = f(12);
    cout << m << endl;
    constexpr A a(2, 3);

    cout << a.x << " "<< a.y << endl;
    return 0;
}
