#include<stdio.h>
int a[100005];

int erfen(int l, int r, int x) {
    while(l < r)  {
        int mid = l + r + 1 >> 1;
        if(a[mid] <= x) l = mid;
        else r = mid - 1;
    }
    return a[l];
}
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    int t;
    for(int i = 1; i <= m; i++) {
        scanf("%d ", &t);
        if(i != m)printf("%d ", erfen(1, n, t));
        else printf("%d", erfen(1, n, t));
    }
    return 0;
}
