/*************************************************************************
	> File Name: 404-01迷宫简易版.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年03月19日 星期四 23时13分11秒
 ************************************************************************/
/*
#include<iostream>
using namespace std;
int n, m;
char a[3005][3005];
int vis[4][2] = { 0, 1, 1, 0, -1, 0, 0, -1 };

int sum= 0;
int dfs1(int x, int y);
int dfs0(int x, int y) {
    for(int i = 0; i < 4; i++) {
        int dx = x + vis[i][0];
        int dy = y + vis[i][1];
        if(dx >= 1 && dx <= n && dy >= 1 && dy <= m && a[dx][dy] == '1') {
            sum++;
            a[dx][dy] = '0';
            dfs1(dx, dy);
        }
    }
    return sum;
}
int dfs1(int x, int y) {
    for(int i = 0; i < 4; i++) {
        int dx = x + vis[i][0];
        int dy = y + vis[i][1];
        if(dx >= 1 && dx <= n && dy >= 1 && dy <= m && a[dx][dy] == '0') {
            sum++;
            a[dx][dy] = '1';
            dfs0(dx, dy);
        }
    }
    return sum;
}




int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    int x, y;
    cin >> x >> y;
    if(a[x][y] == '0') {
        a[x][y] = '1';
        cout << dfs0(x, y) + 1 << endl;
    } else {
        a[x][y] = '0';
        cout << dfs1(x, y) + 1 << endl;
    }
    return 0;
}
*/


#include<iostream>
using namespace std;
int n, m, sx, sy;
char mmap[3005][3005];
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
int check[3005][3005];
int ans = 1;
void dfs(int x, int y) {
    for(int i = 0; i < 4; i++) {
        int tx = x + dir[i][0];
        int ty = y + dir[i][1];
        if(tx < 1 || ty < 1 || tx > n || ty > m) continue;
        if(mmap[tx][ty] != mmap[x][y] && check[tx][ty] == 0) {
            check[tx][ty] = 1;
            ans ++;
            dfs(tx, ty);
        }
    }
}


int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> (&mmap[i][1]);
    }
    cin >> sx >> sy;
    check[sx][sy] = 1;
    dfs(sx, sy);
    cout << ans << endl;
    return 0;
}

