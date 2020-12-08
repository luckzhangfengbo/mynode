/*************************************************************************
	> File Name: 528-关系网络.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年04月24日 星期五 19时41分57秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<queue>
using namespace std;
int n, x, y, mmap[102][102], book[105];
typedef struct node {
    int num, z;
}node;
int main() {
    cin >> n >> x >> y;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> mmap[i][j];
        }
    }
    queue<node>que;
    que.push({x, 0});
    while(!que.empty()){
        node temp = que.front();
        que.pop();
        for(int i = 1; i <= n; i++) {
            if(mmap[temp.num][i] == 1 && book[i] == 0) {
                if(i == y) {
                    cout << temp.z << endl;
                    return 0;
                }
                que.push({i, temp.z + 1});
                book[i] = 1;
            }
        }
    }
    cout << 0 << endl;
    return 0;
}
