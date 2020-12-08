/*************************************************************************
	> File Name: 80-小明看电影.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年03月25日 星期三 20时46分55秒
 ************************************************************************/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<map>
#include<queue>
#include<vector>
using namespace std;

struct node{
    int x, y, z;
};
char mmap[505][505];
int n, m;
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
queue<node>que;
int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> mmap[i][j];
            if(mmap[i][j] == 's') {
                node temp;
                temp.x =i;
                temp.y =j;
                temp.z = 0;
                que.push(temp);
            }
        }
    }
    while(!que.empty()) {
        node temp = que.front();
        que.pop();
        for(int i = 0; i < 4; i++) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if(mmap[x][y] =='g') {
                cout << temp.z + 1 << endl;
                return 0;
            }
            if(mmap[x][y] =='.') {
               mmap[x][y] = '#';
                que.push({x, y, temp.z + 1});
            }
        }
    }
    cout << "No" << endl;
    return 0;
}
 
