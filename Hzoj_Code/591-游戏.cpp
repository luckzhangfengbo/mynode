/*************************************************************************
	> File Name: 591-游戏.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年05月06日 星期三 20时32分19秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;

int main() {
    int n, m;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    if(n & 1) {
        int mid = (n + 1) >> 1;
        if(m < mid)cout << m + 1 << endl;
        else cout << m - 1 << endl;
    } else {
        int mid = n >> 1;
        if(m <= mid) cout << m + 1 << endl;
        else cout << m - 1 << endl;
    }
    return 0;
}
