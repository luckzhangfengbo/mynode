/*************************************************************************
	> File Name: 51-矩形.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年05月12日 星期二 20时10分22秒
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
#define MAX_N 1000

int f[MAX_N + 5];
int a[MAX_N + 5];//向下数，连续白色格子的数量
int s[MAX_N + 5], top = -1;

int main() {
    int n, m, ans = 0;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    a[m + 1] = -1;
    f[m + 1] = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1, val; j <= m; j++) {
            cin >> val;
            if(val == 1)a[j] += 1;
            else a[j] = 0;
        }
        top = -1;
        s[++top] = m + 1;
        for(int j = m; j >= 1; j--) {
            while(a[s[top]] >= a[j])top --;
            f[j] = (s[top] - j) *a[j] + f[s[top]];
            f[j] %= 100007;
            s[++top] = j;
            ans += f[j];
            ans %= 100007;
        }
    }
    cout << ans << endl;

    return 0;
}
