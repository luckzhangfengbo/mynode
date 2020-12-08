/*************************************************************************
	> File Name: 328-楼兰图腾.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年05月24日 星期日 16时30分13秒
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
#define  MAX_N 200005
#define lowbit(x) ((x)&(-x))
int c[MAX_N + 5] = {0};
int a[MAX_N + 5] = {0};
void add(int i,int val, int n) {
    while(i <= n) c[i] += val, i += lowbit(i);
    return;
}

int S(int i) {
    int sum = 0;
    while(i)sum += c[i], i -= lowbit(i);
    return sum;
}

int main() {
    int n;
    long long ans1 = 0, ans2 = 0;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        long long num = S(a[i]);
        ans1 += (a[i] - num - 1) * num;
        ans2 += (i - 1 - num) * (n - a[i] - i + 1 + num);
        add(a[i], 1, n);
    }
    cout << ans2 << " " << ans1 << endl;
    return 0;
}
