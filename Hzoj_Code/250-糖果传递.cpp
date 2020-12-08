/*************************************************************************
	> File Name: 250-糖果传递.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年05月17日 星期日 20时11分16秒
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
/*
#define MAX_N 1000000
long long a[MAX_N + 5];
long long s[MAX_N + 5];
long long g[MAX_N + 5];
long long n, sum = 0, c, ans = 0;
long long main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(long long i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
        sum += a[i];
    }
    c = sum / n;
    for(long long i = 1; i <= n;i++) {
        g[i] = s[i] - i * c;
    }
    sort(g + 1, g + 1 + n);
    c = g[n / 2];
    for(long long i = 1; i <= n; i++) {
        ans += abs(g[i] - c);
    }
    cout << ans << endl;
    return 0;
}
*/
#define MAX_N 1000000
long long a[MAX_N + 5];
long long s[MAX_N + 5];
long long f[MAX_N + 5];
long long n;
int main() {
    cin >> n;
    s[0] = 0;
    for(long long i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    for(long long i = 1; i <= n; i++)f[i] = s[i] - i * (s[n] / n);
    sort(f + 1, f + 1 + n);
    long long tf = f[(n + 1) / 2], cost = 0;
    for(long long i = 1; i <= n; i++) {
        cost += abs(f[i] - tf);
    }
    cout << cost<< endl;
    return 0;
}
