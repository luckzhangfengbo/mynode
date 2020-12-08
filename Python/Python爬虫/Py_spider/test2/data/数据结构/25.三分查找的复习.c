#include <stdio.h>

int find_max(int *data, int length) {
    int l = 0, r = length - 1;
    int sum = 0;
    while (r - l >= 2) {
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l + 2) / 3;
        if(data[m2]>=data[m1]) {
            r = m2;
            sum++;
        } else {
            sum++;
            l = m1 + 1;
        }
    }
    printf("%d ", sum);
    if(data[l] < data[r]) {
        return l;
    } else {
        return r;
    }
    
}

int main() {
    int n, a[100];
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("%d", find_max(a, n));
    return 0;
}
