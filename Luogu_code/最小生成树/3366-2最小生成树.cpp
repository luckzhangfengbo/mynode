/*************************************************************************
	> File Name: 3366-2最小生成树.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年07月08日 星期三 18时48分49秒
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
    int to, val, next;
}edg[400005];

struct node {
    int now, val;
    bool operator < (const node & b) const {
        return this ->val > b.val;
    }
};

int n, m, e_cnt, head[5005], ans, already, vis[5005], dis[5005];


void add_edg(int a, int b, int c) {
    edg[e_cnt].to = b;
    edg[e_cnt].val = c;
    edg[e_cnt].next = head[a];
    head[a] = e_cnt++;
}

int main() {
    memset(head, -1, sizeof(head));
    memset(dis, 0x3F, sizeof(dis));
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add_edg(a, b, c);
        add_edg(b, a, c);
    }
    priority_queue<node>que;
    que.push((node){1, 0});
    while(!que.empty()) {
        node temp = que.top();
        que.pop();
        if(vis[temp.now] == 1) {
            continue;
        }
        vis[temp.now] = 1;
        ans += temp.val;
        already ++;
        if(already == n) {
            break;
        }
        for(int i = head[temp.now]; i != -1; i = edg[i].next) {
            if(vis[edg[i].to] == 0 && dis[edg[i].to] > edg[i].val) {
                dis[edg[i].to] = edg[i].val;
                que.push(node{edg[i].to, edg[i].val});
            }
        }
    }
    if(already == n) {
        cout << ans << endl;
    } else {
        cout << "orz" << endl;
    }

    return 0;
}
