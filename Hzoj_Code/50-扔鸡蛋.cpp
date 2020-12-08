/*************************************************************************
	> File Name: 50-扔鸡蛋.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年05月12日 星期二 18时54分34秒
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
#define MAX_N 32
#define MAX_M 65536
long long dp[MAX_N + 5][MAX_M+ 5];

int main() {
    int n, m;
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(i == 1) {
                dp[i][j] = j;
                continue;
            }
            dp[i][j] = j;
            for(int k = 1; k <= j; k++){
                dp[i][j] = min(dp[i][j], max(dp[i - 1][k], dp[i][j - k]) + 1);
            }
        }
    }
    cout << dp[n][m] - 1 << endl;
    return 0;
}
/*

int main() {
    long long n, m;
    cin >> n >> m;
    if(n == 1) {
        cout << m << endl;
        return 0;
    }
    for(long long k = 1; k <= MAX_N; k++) dp[1][k] = k;
    for(long long i = 2; i <= n; i++) {
        for(long long k = 1; k <= MAX_M; k++) {
            dp[i][k] = dp[i - 1][k - 1] + dp[i][k - 1] + 1;
        }
    }
    long long p = 1;
    while(dp[n][p] < m) {
        p++;
    }
    cout << p << endl;
    return 0;
}
*/
