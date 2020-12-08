/*************************************************************************
	> File Name: 797.差分.cpp
	> Author:fangsong
	> Mail: fangsong517@gmail.com
	> Created Time: 2020年09月08日 星期二 19时01分51秒
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
const int N = 100100;
int a[N], b[N];
void insert(int l, int r, int c) {
    b[l] += c;
    b[r + 1] -= c;
}



int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        insert(i, i, a[i]);
    }
    while(m--) {
        int l, r, c;
        cin >> l >> r >> c;
        insert(l, r, c);
    }
    for(int i = 1; i <= n; i++) {
        b[i] += b[i - 1];
    }

    for(int i = 1; i <= n; i++) {
        cout << b[i] << ' ';
    }
    return 0;
}
