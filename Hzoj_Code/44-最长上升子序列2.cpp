/*************************************************************************
	> File Name: 44-最长上升子序列2.cpp
	> Author:fangsong
	> Mail: fangsong517@gmail.com
	> Created Time: 2020年08月06日 星期四 22时33分38秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<map>
#include<vector>
#include<set>
using namespace std;
#define MAX_N 2000000

int a[MAX_N + 5];
int dp[MAX_N + 5];
int len[MAX_N + 5];
int n, ans = 0;

int find(int *arr, int l, int r, int x) {
    if(l == r) return l;
    int mid = (l + r) >> 1;
    if(arr[mid] < x) return find(arr, mid + 1, r, x);
    else return find(arr, l, mid, x);
}

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        dp[i] = 1;
        len[i] = 0x3f3f3f3f;
    }
    len[++ans] = a[1];
    for(int i = 2; i <= n; i++) {
        dp[i] = find(len, 1, ans + 1, a[i]);
        len[dp[i]] = a[i];
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}
