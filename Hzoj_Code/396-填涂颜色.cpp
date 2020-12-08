/*************************************************************************
	> File Name: 396-填涂颜色.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年03月19日 星期四 23时13分59秒
 ************************************************************************/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<vector>
using namespace std;
int n;
int map[32][32];
int vis[4][2]={0, 1, 1, 0, 0, -1, -1, 0};

void dfs(int x, int y) {
    if(x >= 0 && x <= n+1 && y>=0 && y<=n + 1&&map[x][y]==0) {
        map[x][y]=3;
        for(int i = 0; i < 4; i++) {
            int dx=x + vis[i][0];
            int dy=y + vis[i][1];
            dfs(dx, dy);
        }
    }
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> map[i][j];
        }
    }
    dfs(0, 0);
    for(int i = 1; i <=n ;i++) {
        for(int j = 1; j <= n; j++) {
            if(map[i][j] == 3) {
                map[i][j] = 0;
            } else if(map[i][j] == 0) {
                map[i][j] = 2;
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(j != 1) cout << " ";
            cout << map[i][j];
        }
        cout << endl;
    }
    return 0;
}

