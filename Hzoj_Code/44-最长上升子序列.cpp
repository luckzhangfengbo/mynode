/*************************************************************************
	> File Name: 44-最长上升子序列.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年04月30日 星期四 19时25分41秒
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
int dp[MAX_N + 5];
int a[MAX_N + 5];
int len[MAX_N + 5], ans = 0;
int bs(int *arr, int l, int r, int x) {
    if(l ==  r) return l;
    int mid = (l + r) >> 1;
    if(arr[mid] < x) return bs(arr, mid + 1, r, x);
    return bs(arr, l, mid, x);
}
int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        dp[i] = 1;
        len[i] = 0x3f3f3f3f;
    }
    len[++ans] = a[1];

    for(int i = 2; i <= n; i++) {
        dp[i] = bs(len, 1, ans + 1, a[i]);
        cout << a[i] << " " << dp[i] << " " << a[i]<< endl;
        len[dp[i]] = a[i];
    
        ans = max(dp[i], ans);
    }
    cout << ans << endl;
    return 0;
}
