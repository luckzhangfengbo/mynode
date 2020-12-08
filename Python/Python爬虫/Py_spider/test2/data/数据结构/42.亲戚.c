#include<stdio.h>
#define N 5000
#define swap(a, b) {\
__typeof(a) __temp = a;\
a = b; b = __temp;\
}
int p[N], size[N];
int find(int x) {
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int merge(int a, int b) {
    int fa = find(a), fb = find(b);
    if(fa != fb) {
        if(fa > fb) swap(fa, fb);
        p[fa] = fb;
        size[fb] += size[fa];
        return 1;
    }
    return 0;
}
void init(int n) {
    for(int i = 1; i <=n ;i++) {
        p[i] = i;
        size[i] = 1;
    }
}
int main() {
    int n, m, t;
    scanf("%d%d%d", &n,&m,&t);
    init(n);
    int x, y;
    for(int i = 0; i < m; i++) {
        scanf("%d%d", &x, &y);
        merge(x, y);
    }
    while(t--) {
        scanf("%d%d", &x, &y);
        if(find(x) == find(y)) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}
