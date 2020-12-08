/*************************************************************************
	> File Name: 527-飞跃原野.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年04月01日 星期三 20时01分11秒
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
int m, n, d, check[105][105][105];
char mmap[105][105];

int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};
struct node {
    int x, y, s, d; 
};

int main() {
    cin >> n >> m >> d;
    for(int i = 1; i <= n; i++) {
        cin >> &mmap[i][1];
    }
    queue<node>que;
    que.push({1, 1, 0, d});
    for(int i = 0; i <= d; i++) {
        check[1][1][i] = 1;
    }
    while(!que.empty()) {
        node temp = que.front();
        que.pop();
        for(int i = 0; i < 4; i++) {
            for(int j = 2; j <= temp.d; j++) {
                int x = temp.x + j * dir[i][0];
                int y = temp.y + j * dir[i][1];
                if(x == n && y == m) {
                    cout << temp.s + 1 << endl;
                    return 0;
                }
                if(mmap[x][y] == 0)break;
                if(mmap[x][y] == 'P'&&check[x][y][temp.d - j] == 0) {
                    check[x][y][temp.d - j] = 1;
                    que.push({x, y, temp.s + 1, temp.d - j});
                }
            }
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if(x == n && y == m) {
                cout << temp.s + 1 << endl;
                return 0;
            }
            if(mmap[x][y] == 'P' && check[x][y][temp.d] == 0) {
                check[x][y][temp.d] = 1;
                que.push({x, y, temp.s + 1, temp.d});
            }
        }
    }
    cout << "impossable" << endl;
    return 0;
}
