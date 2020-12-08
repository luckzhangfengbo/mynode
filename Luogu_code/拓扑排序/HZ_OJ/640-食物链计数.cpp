/*************************************************************************
	> File Name: 640-食物链计数.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年07月22日 星期三 19时09分08秒
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

edge edg[500005];
int n, m, head[5005], ans[5005], in_degree[5005], out_degree[5005];

int main() {
    memset(head, -1, sizeof(head));
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edg[i].to = b;
        edg[i].next = head[a];
        head[a] = i;
        in_degree[b] ++;
        out_degree[a]++;
    }
    queue<int> que;
    for(int i = 1; i <= n; i++) {
        if(in_degree[i] == 0) {
            que.push(i);
            ans[i] = 1;
        }
    }
    while(!que.empty()) {
        int t = que.front();
        que.pop();
        for(int i = head[t]; i != -1; i = edg[i].next) {
            int e = edg[i].to;
            in_degree[e] --;
            ans[e] += ans[t];
            ans[e] %= 100000007;
            if(in_degree[e] == 0) {
                que.push(e);
            }
        }
    }
    int fin = 0;
    for(int i = 1; i <= n; i++) {
        if(out_degree[i] == 0) {
            fin += ans[i];
            fin %= 100000007;
        }
    }
    cout << fin << endl;
    return 0;
}
