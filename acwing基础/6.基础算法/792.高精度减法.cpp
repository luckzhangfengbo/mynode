/*************************************************************************
	> File Name: 792.高精度减法.cpp
	> Author:fangsong
	> Mail: fangsong517@gmail.com
	> Created Time: 2020年09月07日 星期一 19时29分51秒
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

bool cmp(vector<int>&A, vector<int>&B) {
    if(A.size() != B.size()) return A.size() > B.size();
    for(int i = A.size() - 1; i >= 0; i--) {
        if(A[i] != B[i]) {
            return A[i] > B[i];
        }
    }
    return true;
}


vector<int>mul(vector<int>&A, vector<int>&B) {
    int t = 0; 
    vector<int>C;
    for(int i = 0; i < A.size(); i++) {
        t = A[i] - t;
        if(i < B.size()) {
            t -= B[i];
        }
        C.push_back((t + 10) % 10);
        if(t < 0) t = 1;
        else t = 0;
    }
    while(C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}

int main() {
    string a, b;
    cin >> a >> b;
    vector<int>A, B, C;
    for(int i = a.size() - 1; i >= 0; i --) A.push_back(a[i] - '0');
    for(int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');
    if(cmp(A, B)) {
        C = mul(A, B);
    } else {
        cout << "-";
        C = mul(B, A);
    }
    for(int i = C.size() - 1; i >= 0; i--) {
        cout<<C[i];
    }
    return 0;
}
