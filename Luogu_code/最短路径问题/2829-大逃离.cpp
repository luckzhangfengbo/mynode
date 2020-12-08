/*************************************************************************
	> File Name: 2829-大逃离.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年07月01日 星期三 20时10分38秒
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
    int from, to, val, next;
};

edge edg[200005];
int n, m,k, edg_cnt, head[5005], ans[5005], ans2[5005], mark[5005],sum[5010];


void make_edge(int a, int b, int c) {
    edg[edg_cnt].from=a;
    edg[edg_cnt].to = b;
    edg[edg_cnt].val = c;
    edg[edg_cnt].next = head[a];
    head[a] = edg_cnt++;
}

int main() {
    memset(ans, 0x3f, sizeof(ans));
    memset(ans2, 0x3f, sizeof(ans2));
    memset(head, -1, sizeof(head));
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        make_edge(a, b, c);
        make_edge(b, a, c);
    }
	int v[5010];
	for(int i=1;i<=n;i++){
		memset(v,0,sizeof(v));
		for(int j=head[i]; j!=-1 ;j=edg[j].next) 
		if(!v[edg[j].to]){//判重
			sum[i]++;	
			v[edg[j].to]=1;
		}
	}
    queue<int>que;
    que.push(1);
    ans[1] = 0;
    mark[1] = 1;
    while(!que.empty()) {
        int t = que.front();
        que.pop();
        mark[t] = 0;
        for(int i = head[t]; i != - 1; i = edg[i].next) {
            if(ans[edg[i].to] > ans[t] + edg[i].val && (sum[edg[i].to] >= k || edg[i].to==n || edg[i].to == 1)) {
                ans[edg[i].to] = ans[t] + edg[i].val;
                if(mark[edg[i].to] == 0) {
                    mark[edg[i].to] = 1;
                    que.push(edg[i].to);
                }
            }
        }
    }
    que.push(n);
    ans2[n] = 0;
    mark[n] = 1;
    while(!que.empty()) {
        int t = que.front();
        que.pop();
        mark[t] = 0;
        for(int i = head[t]; i != - 1; i = edg[i].next) {
            if(ans2[edg[i].to] > ans2[t] + edg[i].val && (sum[edg[i].to] >= k || edg[i].to == n || edg[i].to == 1)) {
                ans2[edg[i].to] = ans2[t] + edg[i].val;
                if(mark[edg[i].to] == 0) {
                    mark[edg[i].to] = 1;
                    que.push(edg[i].to);
                }
            }
        }
    }
    int fin = 99999999;
    for(int i =0; i < edg_cnt; i++)  {
        int t = ans[edg[i].from] + ans2[edg[i].to] + edg[i].val;
        if(fin > t && t != ans[n]) {
            fin = t;
        }
    }
    cout << fin << endl;
    return 0;
}

