/*************************************************************************
	> File Name: 795.高精度乘法.cpp
	> Author:fangsong
	> Mail: fangsong517@gmail.com
	> Created Time: 2020年09月07日 星期一 19时41分53秒
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


vector<int>mul(vector<int>&A, int b) {
    int t = 0;
    vector<int>C;
    for(int i = 0; i < A.size() || t; i++) {
        if(i < A.size()) t += A[i] * b;
        C.push_back(t % 10);
        t /= 10;
    }
    return C;
}

int main() {
    string a;
    int b;
    cin >> a >> b;
    vector<int>A;
    for(int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
    auto C = mul(A, b);
    for(int i = C.size() - 1; i >= 0; i--) {
        cout << C[i];
    }
    return 0;
}
