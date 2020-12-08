/*************************************************************************
	> File Name: 21.template_add.cpp
	> Author:fangsong
	> Mail: fangsong517@gmail.com
	> Created Time: 2020年08月03日 星期一 22时10分11秒
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

template<typename T, typename U>
decltype(T() + U()) add(T a, U b) {
    return a + b;
}
int main() {
    cout << add(2, 3) << endl;
    cout << add(2.3, 3.5) << endl;
    cout << add(2, 3.5) << endl;
    int a;
    double b;
    decltype(a + b) c;
    cout << sizeof(c) << endl;
    return 0;
}
