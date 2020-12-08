/*************************************************************************
	> File Name: 25.bind.cpp
	> Author:fangsong
	> Mail: fangsong517@gmail.com
	> Created Time: 2020年08月10日 星期一 10时28分29秒
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

void func(int x, int y, int z) 
{
    cout << x <<" " <<  y <<" " <<  z << endl;
}

struct A {
    void say() {
        cout << this << " : saying" << endl;
    }
    void run() {
        cout << "hello world" << endl;
    }
};
void count_function_times(function<void()> &p, int &cnt) {
    p();
    cnt += 1;
    return;
}
int main() {
    function<void(int, int)> f = bind(func, 123, std::placeholders::_1, std::placeholders::_2);
    f(100, 456);
    f(200, 789);
    A a;
    cout << &a << endl;
    function<void()> f2 = bind(&A::say, ref(a));//ref是穿&a
    f2();
    int cnt = 0;
    function<void()> f3 = bind(&A::run, ref(a));
    function<void()> f4 = bind(count_function_times, ref(f3), ref(cnt));
    for(int i = 0; i < rand() % 10; i++) {
        f4();
    }
    cout << cnt << endl;
    return 0;
}
