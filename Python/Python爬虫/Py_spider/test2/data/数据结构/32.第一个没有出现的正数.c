#include<stdio.h>
#define N 100000
#define swap(a, b) {\
a ^= b; b^=a;a^=b;\
}

void quick_sort(int *q, int l, int r) {
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
    int a[N], b[N], w[N];
    int n, s = 1;
    scanf("%d", &n);
    int k = 0;
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if(a[i] > 0) {
            b[k++] = a[i];
        }
    }
    quick_sort(b, 0, k - 1);
   w[0] =  b[0];
    for(int i = 1; i < k; i++) {
        if(b[i] != b[i - 1]) {
            w[s++] = b[i];
        }
    }
  /*  for(int i = 0; i < s; i++) {
        printf("%d ", w[i]);
    }
    printf("\n");*/
    for(int i = 1; i <= s + 1; i++) {
        if(w[i - 1] == i) continue;
        printf("%d", i);
        return 0;
    }
    return 0;
}
