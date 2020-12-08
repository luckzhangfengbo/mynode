/*************************************************************************
	> File Name: 535-瓷砖.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年03月19日 星期四 23时11分11秒
 ************************************************************************/
/*
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
int n, m, sx, sy;
char mmap[50][50];

int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
int ans = 1;
void dfs(int x, int y) {
    for(int i = 0; i < 4; i++) {
        int dx = x + dir[i][0];
        int dy = y + dir[i][1];
        if(mmap[dx][dy] == '.') {
            mmap[dx][dy] = 0;
            dfs(dx, dy);
            ans++;
        }
    }
}

int main(){
    cin >> m >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> mmap[i][j];
            if(mmap[i][j] == '@') {
                sx=i;
                sy=j;
            }
        }
    }
    /*
    for(int i = 1; i <= n; i++) {
        cin >> &(mmap[i][1]);
    }*/
 /*   dfs(sx,sy);
    cout << ans << endl;
    return 0;
}
*/

#include<iostream>
using namespace std;
#include<queue>
struct node {
    int x, y;
};
int n, m, ans = 1;
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
char mmap[55][55];
queue<node>que;
int main() {
    cin >> m >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m;j ++) {
            cin >> mmap[i][j];
            if(mmap[i][j] =='@') {
                que.push({i, j});
            }
        }
    }
    while(!que.empty()) {
        node temp = que.front();
        que.pop();
        for(int i = 0; i < 4; i++) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if(mmap[x][y] == '.') {
                mmap[x][y] = 0;
                ans++;
                que.push({x, y});
            }
        }
    }
    cout << ans << endl;
    return 0;
}
