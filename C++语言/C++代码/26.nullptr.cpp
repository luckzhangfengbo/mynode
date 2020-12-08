/*************************************************************************
	> File Name: 26.nullptr.cpp
	> Author:fangsong
	> Mail: fangsong517@gmail.com
	> Created Time: 2020年08月02日 星期日 20时06分29秒
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

int f(int x) {
    cout << "output int value : ";
    cout  << x << endl;
    return 0;
}

int f(int *x) {
    cout << "output address : ";
    cout << x << endl;
    return 0;
}

int main() {
    printf("%lld", (long long)(nullptr));
    //cout << nullptr << endl;
    //cout << NULL << endl;
    int n, *p = &n;
    f(n);
    f(p);
    f(nullptr);//<---- 地址
    f((int)NULL);//0 <---- 当成地址 (void *)0
    return 0;
}
