#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quick_sort(int *data, int left, int right) {
    if(left >= right) return;
    int i = left - 1, j = right + 1, x = data[(left + right) >> 1];
    while(i < j) {
        do i++;while(data[i] < x);
        do j-- ; while (data[j] > x);
        if(i < j)swap(&data[i], &data[j]);
    }
    quick_sort(data, left, j), quick_sort(data, j + 1, right);
}

void select_sort(int *data, int length) {
    int temp;
    for(int i = 0; i < length - 1; i++) {
         temp = i;
        for(int j = i + 1; j < length; j++) {
            if(data[temp] > data[j]) {
                temp  = j;
            }
        }
        if(i != temp) {
            printf("%d %d\n", i, temp);
            swap(&data[i], &data[temp]);
        }
    }
}

void print(int *data, int length) {
    for (int i = 0; i < length; ++i) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", data[i]);
    }
    printf("\n");
}

int main() {
    int m, n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        a[i] = x;
    }
    scanf("%d", &m);
    if (m == 1) {
        select_sort(a, n);
    } else if (m == 2) {
        quick_sort(a, 0, n - 1);
    }
    print(a, n);
    return 0;
}
