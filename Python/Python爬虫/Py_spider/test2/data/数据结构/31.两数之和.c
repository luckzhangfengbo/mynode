#include<stdio.h>
#define swap(a, b) {\
   __typeof(a)  __temp = a;\
   a = b; b = __temp;\
}
int max(int a, int b) {
    if(a > b) {
        return a;
    } else {
        return b;
    }
}
int min(int a, int b) {
    if(a > b) {
        return b;
    } else {
        return a;
    }
}
int p[502];
void binary_search(int *num, int n, int x) {
    int l = 0, r = n - 1;
    while(l <= r) {
        if(num[l] + num[r] == x) {
            int t = 0, w = 0;
            for(int i = 0; i < n; i++) {
                if(num[l] == p[i]) {
                    t = i;
                }
            }
            for(int i = 0; i < n; i++) {
                if(num[r] == p[i]) {
                    w = i;
                }
            }
            printf("%d %d\n", min(t, w), max(t, w));
            return 0;
        }
        if(num[l] + num[r] > x) {
            r--;
        } else if(num[l] + num[r] < x) {
            l++;
        }
    }
    return ;
}

void quick_sort(int *num, int l, int r) {
    if(l >= r) return;
    int i = l - 1, j = r + 1, x = num[(l + r) >> 1];
    while(i < j) {
        do i++; while(num[i] < x);
        do j-- ; while(num[j] > x);
        if(i < j) {
            swap(num[i], num[j]);
        }
    }
    quick_sort(num, l, j), quick_sort(num, j + 1, r);
}

int main() {
    int n, str[1505];
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &str[i]);
        p[i + 1] = str[i];
    }
    quick_sort(str, 0, n - 1);
    int x ; 
    scanf("%d", &x);
    binary_search(str, n, x);
    return 0;
}
