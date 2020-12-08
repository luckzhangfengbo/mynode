/*************************************************************************
	> File Name: 3371-单源最短路径弱化版.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年05月27日 星期三 21时21分27秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

struct node {
    int e, dist, next;
};

struct point {
    int now, dist;
    bool operator< (const point &b) const {
        return this->dist > b.dist;
    }
};


int n, m, s, cnt,  ans[10005], head[10005];
node edge[500005];
char mark[10005][10005];

int main() {
    memset(head, -1, sizeof(head));
    memset(ans, 0x3f, sizeof(ans));
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >>c;
        if (!mark[a][b]) {
            edge[cnt].e = b;
            edge[cnt].dist = c;
            edge[cnt].next = head[a];
            head[a] = cnt;
            cnt++;
        } else {
            int ind = head[a];
            while (edge[ind].e != b) {
                ind = edge[ind].next;
            }
            edge[ind].dist = min(edge[ind].dist, c);
        }
    }
    priority_queue<point> que;
    que.push({s, 0});
    while (!que.empty()) {
        point t = que.top();
        que.pop();
        if (ans[t.now] != 0x3f3f3f3f) continue;
        ans[t.now] = t.dist;
        for (int i = head[t.now]; i != -1; i = edge[i].next) {
            if (ans[edge[i].e] == 0x3f3f3f3f) que.push({edge[i].e, t.dist + edge[i].dist});
        }
    }
    for (int i = 1; i <= n; i++) {
        i == 1 || cout << " ";
        if (ans[i] == 0x3f3f3f3f) cout << 0x7fffffff;
        else cout << ans[i];
    }
    cout << endl;
    return 0;
}
