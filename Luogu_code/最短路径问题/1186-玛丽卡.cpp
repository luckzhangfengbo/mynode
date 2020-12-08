/*************************************************************************
	> File Name: 1186-玛丽卡.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年06月10日 星期三 20时23分21秒
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

struct edge {
    int to, val, next;
};

edge edg[1000005];
int n, m, edg_cnt, head[1005], ans[1005], ans_max, que_mark[1005], from[1005];

int main() {
    memset(head, -1, sizeof(head));
    memset(ans, 0x3f, sizeof(ans));
    cin >> n >> m;
    for(int i = 1; i <= m ; i++) {
        int a, b ,c;
        cin >> a >> b >> c;
        edg[edg_cnt].to = b;
        edg[edg_cnt].val = c;
        edg[edg_cnt].next = head[a];
        head[a] = edg_cnt;
        edg_cnt++;
        edg[edg_cnt].to = a;
        edg[edg_cnt].val = c;
        edg[edg_cnt].next = head[b];
        head[b] = edg_cnt;
        edg_cnt++;
    }
    queue<int> que;
    que.push(1);
    ans[1] = 0;
    que_mark[1] = 1;
    while(!que.empty()) {
        int t = que.front();
        que.pop();
        que_mark[t] = 0;
        for(int cnt = head[t]; cnt != -1; cnt = edg[cnt].next) {
            if(ans[edg[cnt].to] > ans[t] + edg[cnt].val) {
                ans[edg[cnt].to] = ans[t] + edg[cnt].val;
                from[edg[cnt].to] = t;
                if(que_mark[edg[cnt].to] == 0) {
                    que_mark[edg[cnt].to] = 1;
                    que.push(edg[cnt].to);
                }
            }

    
        }
    }
    for(int i = n; i != 1; i = from[i]) {
        int cnt1 = head[i], cnt2 = head[from[i]], v;
        while(edg[cnt1].to != from[i]) {
            cnt1 = edg[cnt1].next;
        }
        while(edg[cnt2].to != from[i]) {
            cnt1 = edg[cnt2].next;
        }
    }

    return 0;
}
