/*************************************************************************
	> File Name: 406-水坑数量.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年03月19日 星期四 23时15分36秒
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
char map[2003][2003];
int vis[8][2] = {0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1, -1, 0, -1, 1};

void dfs(int x, int y) {
    for(int i = 0; i < 8; i++) {
        int dx = x + vis[i][0];
        int dy = y + vis[i][1];
        if(dx >= 1&& dx <= n && dy >= 1&& dy <= m && map[dx][dy]=='#') {
            map[dx][dy] = '.';
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
            if(map[i][j] == '#') {
                sum++;
                dfs(i, j);
            }
        }
    }
    cout << sum << endl;
}


