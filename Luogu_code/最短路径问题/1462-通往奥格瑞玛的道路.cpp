/*************************************************************************
	> File Name: 1462-通往奥格瑞玛的道路.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年07月01日 星期三 20时42分55秒
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
};
struct node {
    int now, val;
    bool operator< (const node & b) const {
        return this->val > b.val;
    }
};

edge edg[100005];
int n, m , b,edg_cnt, cost[10005], head[10005], ans[10005];

void make_edge(int a, int b, int c) {
    edg[edg_cnt].to = b;
    edg[edg_cnt].val = c;
    edg[edg_cnt].next = head[a];
    head[a] = edg_cnt++;
}

int dijstra(int mmax) {
    memset(ans, 0x3f, sizeof(ans));
    priority_queue<node>que;
    que.push((node){1, 0});
    ans[1] = 0;
    while(!que.empty()) {
        node temp = que.top();
        que.pop();
        if(temp.val > ans[temp.now]) {
            continue;
        }
        for(int i = head[temp.now]; i != -1; i = edg[i].next) {
            int to = edg[i].to, va = edg[i].val;
            if(cost[to] <= mmax && ans[to] > temp.val + va) {
                ans[to] = temp.val + va;
                que.push((node){to, ans[to]});
            }
        }
    }
    if(ans[n] > b || ans[n] == 0x3f3f3f3f) {
        return 0;
    } else {
        return 1;
    }
}

int main() {
    memset(head, -1, sizeof(head));
    cin >> n >> m >> b;
    for(int i = 1; i <= n; i++) {
        cin >> cost[i];
    }
    for(int i = 0; i < m; i++) {
        int a, b , c;
        cin >> a >> b >> c;
        make_edge(a, b, c);
        make_edge(b, a, c);
    }
    int l = 0, r = 1000000000;
    while(l != r) {
        int mid = (l + r) / 2;
        if(dijstra(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    if(l == 1000000000) {
        cout << "AFK" << endl;
    } else {
        cout << l << endl;
    }
    return 0;
}
