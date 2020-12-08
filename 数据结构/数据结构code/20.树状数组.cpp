/*************************************************************************
	> File Name: 20.树状数组.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年05月24日 星期日 15时57分47秒
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
#define  MAX_N 1000
#define lowbit(x) ((x)&(-x))
int c[MAX_N + 5] = {0};

void add(int i,int val, int n) {
    while(i <= n) c[i] += val, i += lowbit(i);
    return;
}

int sum(int i) {
    int sum = 0;
    while(i)sum += c[i], i -= lowbit(i);
    return sum;
}

int main() {
    int n, a;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a;
        add(i, a, n);
    }
    for(int i = 1; i <= n; i++) {
        cout << sum(i) - sum(i - 1) << endl;
    }
    return 0;
}
