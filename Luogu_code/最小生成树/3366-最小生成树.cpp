/*************************************************************************
	> File Name: 3366-最小生成树.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年07月08日 星期三 18时22分38秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;

struct edge{
    int from, to, val;
}edg[200005];

int n, m, ans, my_union[5005], already = 1;

bool cmp(edge a, edge b) {
    return a.val < b.val;
}

int find_root(int x) {
    if(my_union[x] != x) {
        return my_union[x] = find_root(my_union[x]);
    }
    return x;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> edg[i].from >> edg[i].to >> edg[i].val;
    }
    for(int i = 1; i <= n; i++) {
        my_union[i] = i;
    }
    sort(edg, edg + m, cmp);
    for(int i = 0; i < m; i++) {
        int aroot = find_root(edg[i].from), broot = find_root(edg[i].to);
        if(aroot != broot) {
            already ++;
            ans += edg[i].val;
            my_union[aroot] = broot;
            if(already == n) {
                break;
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
