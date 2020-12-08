/*************************************************************************
	> File Name: 372-双生序列.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年05月29日 星期五 21时55分10秒
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
#define MAX_N 500000

int a[MAX_N + 5], b[MAX_N + 5];


int main() {
    ios::sync_with_stdio(false);
    int n, p = 0;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    int top1 = -1, top2 = -1;
    while(p < n) {
        while(top1 != -1 && a[p] < a[top1]) -- top1;
        while(top2 != -1 && b[p] < b[top2]) -- top2;
        if(top1 - top2) break;
        a[++top1] = a[p];
        b[++top2] = b[p];
        p++;
    }
    cout << p << endl;
    return 0;
    
}
