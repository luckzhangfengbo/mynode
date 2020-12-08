/*************************************************************************
	> File Name: 405-01迷宫.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年03月19日 星期四 23时14分55秒
 ************************************************************************/
#include<iostream>
#include<queue>
using namespace std;
int n, m , k, ans;
struct node {
    int x, y;
};
char mmap[3005][3005];
int check[3005][3005];
int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};
queue<node>que;

void dfs(int x, int y) {
    for(int i = 0; i < 4; i++) {
        int dx = x + dir[i][0];
        int dy = y + dir[i][1];
        if(check[dx][dy] == 0 && mmap[dx][dy] != mmap[x][y] && mmap[dx][dy]) {
            ans ++;
            check[dx][dy] = 1;
            que.push({dx, dy});
            dfs(dx, dy);
        }
    }
}


int main() {
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) {
        cin >> (&mmap[i][1]);
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(check[i][j] == 0) {
                ans = 1;
                check[i][j] = 1;
                que.push({i, j});
                dfs(i, j);
                while(!que.empty()) {
                    node temp = que.front();
                    que.pop();
                    check[temp.x][temp.y] = ans;
                }
            }
        }
    }
    for(int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        cout << check[a][b] << endl;
    }
    return 0;
}

