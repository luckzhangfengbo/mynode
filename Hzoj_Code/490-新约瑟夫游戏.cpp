/*************************************************************************
	> File Name: 490-新约瑟夫游戏.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年04月28日 星期二 18时51分07秒
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
const int MAX_N = 32767;
int f[MAX_N + 5];


int main() {
    int n;
    ios::sync_with_stdio(false);
    cin >> n;
    f[1] = 1;
    for(int i = 2; i <= n; i++) {
        f[i] = (f[i - 1] + 2 - 1) % i + 1;
    }
    int x = n;
    while(f[x] - x)x = f[x];
    cout << n + x << endl;
    return 0;
}
