/*************************************************************************
	> File Name: 398-马的遍历.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年04月01日 星期三 18时48分16秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

int mmap[405][405];
int dir[8][2] = {1, 2, 2, 1, 2, -1, 1, -2, -1, -2, -2, -1, -2, 1, -1, 2};
struct node{
    int x, y, z;
};
int n, m;
int main() {
    int xx, yy;
    cin >> n >> m >> xx >>yy;
    queue<node>que;
    que.push({xx, yy, 0});
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            mmap[i][j] = -1;
        }
    }
    node temp;
    while(!que.empty()) {
        temp = que.front();
        que.pop();
        for(int i = 0; i < 8; i++) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if(x < 1|| y < 1 || x > n || y > m || mmap[x][y] != -1)continue;
            mmap[x][y] = temp.z + 1;
            que.push({x, y, temp.z + 1});
        }
    }
      mmap[xx][yy] = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(j != 1) cout << " ";
            cout << mmap[i][j];
        }
        cout << endl;
    }
    return 0;
}
