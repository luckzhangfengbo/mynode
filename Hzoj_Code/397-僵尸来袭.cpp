/*************************************************************************
	> File Name: 397-僵尸来袭.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年03月19日 星期四 23时14分18秒
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
int map[105][105];
int vis[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};

void dfs(int x, int y) {
    for(int i = 0; i < 4; i++) {
        int dx = x + vis[i][0];
        int dy = y + vis[i][1];
        if(dx >= 1&& dx <= n && dy >= 1&& dy <= m && map[dx][dy]!=0) {
            map[dx][dy] = 0;
            dfs(dx, dy);
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> map[i][j];
        }
    }
    int sum = 0;
    for(int i = 1; i <=n; i++) {
        for(int j= 1; j <= m; j++) {
            if(map[i][j] != 0) {
                sum++;
                dfs(i, j);
            }
        }
    }
    cout << sum << endl;
}


