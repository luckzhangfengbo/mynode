/*************************************************************************
	> File Name: 536-最大黑色区域.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年03月19日 星期四 23时12分01秒
 ************************************************************************/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<vector>
using namespace std;
int n, m;
char mmap[105][105];
int sum, maxn;
int vis[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
void dfs(int x, int y) {
    for(int i = 0; i < 4; i++) {
        int dx = x + vis[i][0];
        int dy = y + vis[i][1];
        if( mmap[dx][dy] == '1') {
            sum++;
            mmap[dx][dy] = '0';
            dfs(dx, dy);
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
    cin >> (&mmap[i][1]);
    }
    for(int i = 1; i <=n; i++) {
        for(int j = 1; j <= m; j++) {
            if(mmap[i][j] == '1') {
                mmap[i][j] = '0';
                sum = 1; 
                dfs(i, j);
                maxn = max(maxn, sum);
            }
        }
    }
    cout << maxn << endl;
}

