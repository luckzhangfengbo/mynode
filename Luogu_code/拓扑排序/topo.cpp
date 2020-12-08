/*************************************************************************
	> File Name: topo.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年07月22日 星期三 18时30分41秒
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

struct edge{
    int to, next;
};

edge edg[50];
int n, m, head[50], in_degree[50], out_degree[50];

int main() {
    memset(head, -1, sizeof(head));
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edg[i].to = b;
        edg[i].next = head[a];
        head[a] = i;
        in_degree[b]++;
    }

    queue<int>que;
    for(int i = 1; i <= n; i++) {
        if(in_degree[i] == 0) {
            que.push(i);
        }
    }
    while(!que.empty()) {
        int temp = que.front();
        que.pop();
        cout << temp << " ";
        for(int i = head[temp]; i != -1; i = edg[i].next) {
            int e = edg[i].to;
            in_degree[e] --;
            if(in_degree[e] == 0) {
                que.push(e);
            }
        }
    }
    return 0;
}
