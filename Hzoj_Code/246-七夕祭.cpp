/*************************************************************************
	> File Name: 246-七夕祭.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年05月28日 星期四 14时59分50秒
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
#define max_n 100000
long long x[max_n + 5], y[max_n + 5];
long long n, m, c;
long long sum[max_n + 5];
long long solve(long long *arr, long long n, long long avg) {
    for(long long i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + arr[i] - avg;
    }
    sort(sum + 1, sum + n + 1);
    long long val = sum[(n + 1) / 2], ans = 0;
    for(long long i = 1; i <= n; i++) {
        ans += abs(sum[i] - val);
    }
    return ans;
}

int main() {
    cin >> n >> m >> c;
    for(long long i = 0; i < c; i++) {
        long long a ,b;
        cin >> a >> b;
        x[a] += 1;
        y[b] += 1;
    }
    long long ans = 0;
    if(c % n == 0 && c % m == 0) {
        cout << "both ";
        ans = solve(x, n, c / n) + solve(y, m, c / m);
    } else if(c % n == 0) {
        cout << "row ";
        ans = solve(x, n, c / n);
    } else if(c % m == 0){
        cout << "column ";
        ans = solve(y, m, c / m);
    } else {
        cout << "impossible" << endl;
        return 0;
    }
    cout << ans << endl;
    return 0;
}
