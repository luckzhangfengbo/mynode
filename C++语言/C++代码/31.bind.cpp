/*************************************************************************
	> File Name: 31.bind.cpp
	> Author:fangsong
	> Mail: fangsong517@gmail.com
	> Created Time: 2020年08月13日 星期四 11时18分02秒
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
#include<functional>
using namespace std;

int add(int a, int b) {
    cout << a << " " << b << endl;
    return a + b;
}
int add2(int a, int b, int c) {
    cout << a << " " << b << " " << c << endl;
    return a + b + c;
}

int add_cnt(function<int(int, int)>func, int &n, int a, int b) {
    n++;
    return func(a, b);
}


int main() {
    add(3, 4);
    add(5, 6);
    function<int(int)> f = bind(add, 5, placeholders::_1);
    cout << f(3) << endl;
    cout << f(4) << endl;
    cout << f(5) << endl;
    function<int(int, int)> f2 = bind(add, placeholders::_2, placeholders::_1);
    f2(3, 4);
    function<int(int, int)> f3 = bind(add2, placeholders::_2, 6,placeholders::_1);
    f3(9, 10);
    function<int(int, int, int)> f4 = bind(add2, placeholders::_1, placeholders::_3, placeholders::_2);
    f4(1, 2, 3);
    //绑定一个可以统计函数执行次数的方法
    int n = 0;
    function<int(int, int)> f5 = bind(add_cnt, add, ref(n), placeholders::_1, placeholders::_2);//n其实是拷贝了一份，传过去，n并没有变,当加上ref是是加&
    f5(99, 88);
    f5(99, 88);    
    f5(99, 88);
    cout << n << endl;
    //为什么n输出0;


    return 0;
}
