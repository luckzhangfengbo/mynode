/*************************************************************************
	> File Name: 529-龙与虫.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年04月01日 星期三 20时34分56秒
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

int n, m, check[152][152];
char mmap[152][152];
struct node {
    int x, y, step;
};
int dir[8][2] = {
    0, 1, 1, 0, 0, -1, -1, 0,
    1, 1, -1, -1, 1, -1, -1, 1
};

int func(){
    int a, b, c, d;
    cin >> c >> d >> a >> b;
    if(!a)return 0;
    memset(check, 0, sizeof(check));
    for(int i = 0; i < 8; i++) {
        for(int j = 1; 1; j++) {
            int x = c + j * dir[i][0];
            int y = d + j * dir[i][1];
            if(mmap[x][y] != 'O')break;
            check[x][y] = 2;
        }
    }
    check[c][d] = 2;
    if(check[a][b] == 2) {
        cout << 0 << endl;
        return 1;
    }
    queue<node>que;
    que.push({a, b, 0});
    check[c][d] = 1;
    while(!que.empty()) {
        node temp = que.front();
        que.pop();
        for(int i = 0; i < 4; i++) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if(check[x][y] == 2) {
                cout << temp.step + 1 << endl;
                return 1;
            }
            if(mmap[x][y] == 'O' && check[x][y] != 1) {
                check[x][y] = 1;
                que.push({x, y, temp.step + 1});
            }
        }
    }
    cout << "Impossible!" << endl;
return 1;
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> &mmap[i][1];
    }
    while(func()){}
    return 0;
}
