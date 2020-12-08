/*************************************************************************
	> File Name: 1342-请柬.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年06月11日 星期四 15时25分13秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <queue>
#include <cstdio>
using namespace std;

struct edge {
    int to, next, val;//终点，下一条边，权值
};

struct node {
    int now, val;////现在在哪，到这位置路径最小多少
    bool operator< (const node &b) const {
        return this->now > b.now;
    }
};

edge edg[1000005], edg2[1000005];//去回
int n, m, head[1000005], head2[1000005], ans[1000005], ans2[1000005];

int main() {
    memset(ans, 0x3F, sizeof(ans));
    memset(ans2, 0x3F, sizeof(ans2));
    memset(head, -1, sizeof(head));
    memset(head2, -1, sizeof(head2));
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        edg[i].to = b;
        edg[i].val = c;
        edg[i].next = head[a];
        head[a] = i;
        edg2[i].to = a;
        edg2[i].val = c;
        edg2[i].next = head2[b];
        head2[b] = i;
    }
    priority_queue<node> que;
    que.push((node){1, 0});
    ans[1] = 0;
    while (!que.empty()) {
        node temp = que.top();
        que.pop();
        if (temp.val > ans[temp.now]) {
            continue;
        }
        for (int cnt = head[temp.now]; cnt != -1; cnt = edg[cnt].next) {
            if (ans[edg[cnt].to] > temp.val + edg[cnt].val) {
                ans[edg[cnt].to] = temp.val + edg[cnt].val;
                que.push((node){edg[cnt].to, ans[edg[cnt].to]});
            }
        }
    }
    que.push((node){1, 0});
    ans2[1] = 0;
    while (!que.empty()) {
        node temp = que.top();
        que.pop();
        if (temp.val > ans2[temp.now]) {
            continue;
        }
        for (int cnt = head2[temp.now]; cnt != -1; cnt = edg2[cnt].next) {
            if (ans2[edg2[cnt].to] > temp.val + edg2[cnt].val) {
                ans2[edg2[cnt].to] = temp.val + edg2[cnt].val;
                que.push((node){edg2[cnt].to, ans2[edg2[cnt].to]});
            }
        }
    }
    long long fin = 0;
    for (int i = 2; i <= n; i++) {
        fin += ans[i] + ans2[i];
    }
    printf("%ld\n", fin);
    return 0;
}
