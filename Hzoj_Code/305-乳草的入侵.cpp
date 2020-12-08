/*************************************************************************
	> File Name: 305-乳草的入侵.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年04月01日 星期三 19时09分07秒
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
int n, m, x, y;
char mmap[101][101];
struct node {
    int x, y, step;
};

int dir[8][2] = {
    1, 0, 0, 1, -1, 0, 0, -1,
    1, 1, 1, -1, -1, 1, -1, -1 
};

int main() {
  cin >> m >> n >> y >> x;
    for(int i = 1; i <= n; i++) {
        cin >> &mmap[i][1];
    }
    queue<node>que;
    que.push({n - x + 1, y, 0});
    mmap[n - x + 1][y] = '*';
    int ans =0;
    while(!que.empty()) {
        node temp = que.front();
        que.pop();
        ans = temp.step;
        for(int i = 0; i < 8; i++) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if(mmap[x][y] == '.') {
                mmap[x][y] = '*';
                que.push({x, y, temp.step + 1});
            }
        }
    }
    cout << ans << endl;
    return 0;
}
