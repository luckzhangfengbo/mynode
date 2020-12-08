/*************************************************************************
	> File Name: 343-最长公共上升子序列.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年04月30日 星期四 20时28分08秒
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
#define N 3005
int a[N], b[N];
int f[N][N];
int n;
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    for(int i = 1; i <= n; i++) {
        int maxv = 0;//前边最多有多少个满足b[j]<a[i]的
        for(int j = 1; j <= n; j++) {
            f[i][j] = f[i - 1][j];
            if(a[i] == b[j])f[i][j] = max(f[i][j], maxv + 1);//更新答案
            if(b[j] < a[i])maxv = max(maxv, f[i][j]);//更新maxv 
        }
    }
    int res = 0;
    for(int i = 1; i <= n; i++) {
        res = max(res, f[n][i]);
    }
    cout << res << endl;
}
