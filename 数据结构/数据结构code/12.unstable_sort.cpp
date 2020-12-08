/*************************************************************************
	> File Name: 12.unstable_sort.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年02月20日 星期四 18时31分59秒
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define swap(a, b) {\
    __typeof(a) __temp = a;\
    a = b; b = __temp;\
}
#define TEST(arr, n, func, args...) {\
    int *num = (int *)malloc(sizeof(int) * n);\
    memcpy(num, arr, sizeof(int) * n);\
    output(num, n);\
    printf("%s = ", #func);\
    func(args);\
    output(num, n);\
    free(num);\
}

void select_sort(int *num, int n) {
    for(int i = 0; i < n - 1; i++) {
        int ind = i;
        for(int j = i + 1; j < n; j++) {
            if(num[ind] > num[j]) ind = j;
        }
        swap(num[ind], num[i]);
    }
    return;
}

void quick_sort(int *num, int l, int r) {
    if(r < l) return;
    int x = l, y = r, mid = (l + r) >> 1;
    while(x <= y) {
        while(x <= y && num[y] >= num[mid]) y--;
        //if(x < y)num[x++] = num[y];
        while(x <= y && num[x] <= num[mid]) x++;
        //if(x < y)num[y--] = num[x];   
        if(x <= y) {
            swap(num[x], num[y]);
            x ++, y--;
        }
    }
    quick_sort(num, l, x - 1);
    quick_sort(num, x + 1, r);
    return;
}

void randint(int *arr, int n) {
    while(n--) arr[n] = rand() % 100;
    return;
}

void output(int *num, int n) {
    printf("[");
    for(int i = 0; i < n; i++) {
        printf("%d ", num[i]);
    }
    printf("]\n");
}

int main() {
    srand(time(0));
    #define max_op 20
    int arr[max_op];
    randint(arr, max_op);
    TEST(arr, max_op, select_sort, num, max_op);
    TEST(arr, max_op, quick_sort, num, 0 ,max_op - 1);
    return 0;
}
