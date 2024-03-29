/*************************************************************************
	> File Name: 52-古老的打字机.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年04月30日 星期四 20时31分06秒
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
#define MAX_N 1000000
long long dp[MAX_N + 5];
long long c[MAX_N + 5];

inline long long S(long long x) {
    return x * x;
}

int main() {
    long long n, M;
    cin >> n >> M;
    c[0] = 0;
    for(long long i = 1; i <= n; i++) {
        cin >> c[i];
        c[i] += c[i - 1];
    }
    for(long long i = 1; i <= n; i++) {
        dp[i] = dp[i - 1] + S(c[i] - c[i - 1]) + M;
        for(long long j = 0; j < i - 1; i++) {
            dp[i] = min(dp[i], dp[j] + S(c[i] - c[j]) + M);
        }
    }
    cout << dp[n] << endl;
    return 0;
}
