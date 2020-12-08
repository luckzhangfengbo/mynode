#include<stdio.h>
int a[100005];
#define swap(a, b) {\
a^=b;b^=a;a^=b;\
}
int erfen(int l, int r, int x) {
    while(l < r)  {
        int mid = l + r + 1 >> 1;
        if(a[mid] <= x) l = mid;
        else r = mid - 1;
    }
    return a[l];
}
void quick_sort(int q[], int l, int r)
{
  if(l >= r)return;
  int i = l - 1, j = r + 1, x = q[l + r >> 1];
  while(i < j)
  {
    do i ++; while(q[i] < x);
    do j --; while(q[j] > x);
    if( i < j )swap(q[i], q[j]);
  }
  quick_sort(q, l, j), quick_sort(q, j + 1, r);
}
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    quick_sort(a, 1, n);
    int t;
    for(int i = 1; i <= m; i++) {
        scanf("%d ", &t);
        if(i != m)printf("%d ", erfen(1, n, t));
        else printf("%d", erfen(1, n, t));
    }
    return 0;
}
