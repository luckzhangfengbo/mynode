/*************************************************************************
	> File Name: 71-朋友圈.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年04月28日 星期二 09时13分31秒
 ************************************************************************/
/*
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
const int N = 10000;
int p[N];

int find(int x) {
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) p[i] = i;
    int w, a, b;
    while(m--) {
        cin >> w >> a >> b;
        if(w == 1) p[find(a)] = p[find(b)];
        else {
            if(find(a) == find(b)) puts("Yes");
            else {
                puts("No");
            }
        }
    }
    return 0;
}
*/

#include<iostream>
using namespace std;
const int MAX_N = 10000;
struct UnionSet{
    int fa[MAX_N + 5];
    void init(int n) {
        for(int i = 1; i <= n; i++) fa[i] = i;
    }
    int get(int x) {
        if(x != fa[x]) fa[x] = get(fa[x]);
        return fa[x];
    }
    void merge(int a, int b) {
        fa[get(a)] = get(b);
    }

};

UnionSet u;
int main() {
    int n, m;
    cin >> n >> m;
    u.init(n);
    for(int i = 0;i < m; i++) {
        int a , b , c;
        cin >> a >> b >> c;
        switch(a) {
            case 1:u.merge(b, c);break;
            case 2:cout << (u.get(b) - u.get(c) ? "No" : "Yes") << endl; break;
        }
    }
    return 0;
}

