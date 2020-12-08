/*************************************************************************
	> File Name: 791.高精度加法.cpp
	> Author:fangsong
	> Mail: fangsong517@gmail.com
	> Created Time: 2020年09月07日 星期一 19时22分11秒
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

vector<int>add(vector<int>&A, vector<int>&B) {
    if(A.size() < B.size()) return add(B, A);
    vector<int>C;
    int t = 0;
    for(int i = 0; i < A.size(); i++) {
        if(i < A.size()) t += A[i];
        if(i < B.size()) t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }
    if(t) C.push_back(1);
    return C;
}

int main() {
    string a, b;
    vector<int>A;
    vector<int>B;
    cin  >> a >> b;
    for(int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
    for(int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');
    auto C = add(A, B);
    for(int i = C.size() -1; i >= 0; i--) {
        cout << C[i];
    }
    return 0;
}
