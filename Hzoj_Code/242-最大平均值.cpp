/*************************************************************************
	> File Name: 242-最大平均值.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年05月17日 星期日 15时56分28秒
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
#define MAX_N 100000
#define INF 0x3f3f3f3f
long long a[MAX_N + 5];
long long b[MAX_N + 5];
long long sum[MAX_N + 5];
long long n, m;
bool check(long long A) {
    for(long long i = 1; i <= n; i++) {
        b[i] = a[i] - A;
        sum[i] = b[i] + sum[i - 1];
    }
    long long Y = 0;
    for(long long j = m; j <= n; j++) {
        Y = min(Y, sum[j - m]);
        if(sum[j] - Y >= 0) return true;
    }
    return false;
}

long long bs(long long l, long long r) {
    if(l == r) return l;
    long long mid = (l + r + 1) >> 1;
    if(check(mid)) return bs(mid, r);
    return bs(l, mid - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    long long l = INF, r = -INF;
    for(long long i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] *= 1000;
        l = min(l, a[i]);
        r = max(r, a[i]);
    }
    cout << bs(l, r) << endl;
    return 0;
}
