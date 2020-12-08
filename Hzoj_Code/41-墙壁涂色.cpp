/*************************************************************************
	> File Name: 41-墙壁涂色.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年04月26日 星期日 20时30分22秒
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

int f[1000][15][15];

int main() {
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < k; j++) {
            f[1][i][j] = (i == j);
        }
    }
    for(int t = 2; t <= n; t++) {
        for(int i  = 0; i < k; i++) {
            for(int j = 0; j < k; j++) {
                for(int l = 0; l < k; l++) {
                if(l - j)f[t][i][j] += f[t - 1][i][l];
                }
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < k; j++) {
            if(i - j)ans += f[n][i][j];
        }
    }
    cout << ans << endl;
    return 0;
}
