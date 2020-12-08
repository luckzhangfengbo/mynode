/*************************************************************************
	> File Name: 362-食物链.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年04月23日 星期四 20时16分35秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>

#define max_n 50000
int fa[max_n + 5], val[max_n + 5];
int n;

void init(int n) {
    for(int i = 1; i <= n; i++) {
        fa[i] = i;
        val[i] = 0;
    }
    return;
}


int get(int x) {
    if(x == fa[x]) return x;
    int root = get(fa[x]);
    val[x] += val[fa[x]];
    val[x] %= 3;
    return fa[x] = root;
}

int merge(int x, int y, int t) {
    int a = get(x), b = get(y);
    if(a == b) {
       return  (val[x] - val[y] - t)%3 == 0;
    }
    fa[a] = b;
    val[a] = (t + val[y] - val[x] + 3) % 3;
    return 1;
}

int main() {
    int n, k, ans = 0;
    scanf("%d%d", &n, &k);
    init(n);
    for(int i = 0; i < k; i++) {
        int x, y, t;
        scanf("%d%d%d", &t, &x, &y);
        t -= 1;
        if(x <= n && y <= n && merge(x, y, t))continue;
        ans += 1;
    }
    printf("%d", ans);
    return 0;
}
