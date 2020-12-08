/*************************************************************************
	> File Name: 636-旅行计划.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年07月22日 星期三 20时17分04秒
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

edge edg[200005];

int n, m, head[100005], in_degree[100005], ans[100005];

int main() {
    ios::sync_with_stdio(false);
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
    queue<int> que;
    for(int i = 1; i <= n; i++) {
        if(in_degree[i] == 0) {
            ans[i] = 1;
            que.push(i);
        }
    }
    while(!que.empty()) {
        int t = que.front();
        que.pop();
        for(int i = head[t]; i != -1; i = edg[i].next){
            int e = edg[i].to;
            ans[e] = max(ans[e], ans[t] + 1);
            in_degree[e]--;
            if(in_degree[e] == 0) {
                que.push(e);
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}
