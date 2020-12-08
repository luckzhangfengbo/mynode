/*************************************************************************
	> File Name: 11.stable_sort.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年02月20日 星期四 16时15分37秒
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#define swap(a, b) {\
    a^= b; b ^= a; a^=b;\
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

void insert(int *num, int n) {
    for(int i = 1; i < n; i++) {
        for(int j = i; j > 0 && num[j] < num[j - 1]; j--) {
            swap(num[j], num[j - 1]);
        }
    }
    return;
}

void bubble_sort(int *num, int n) {
    int times;
    for(int i = 0; i < n - 1 && times; i++) {
        times = 0;
        for(int j = 0; j < n - i - 1; j++) {
            if(num[j] > num[j + 1]) {
                swap(num[j], num[j + 1]);
                times++;
            }
        }
    }
    return;
}

void merge_sort(int *num, int l, int r) {
    if(r - l <= 1) {
        if(r - l == 1 && num[l] > num[r]) {
            swap(num[l], num[r]);
        }
        return;
    }
    int mid = (l + r) >> 1;
    merge_sort(num, l, mid);
    merge_sort(num, mid + 1, r);
    int *temp = (int *)malloc(sizeof(int)*(r - l + 1));
    int p1 = l, p2 = mid + 1, k = 0;
    while(p1 <= mid||p2 <= r) {
        if(p2 > r || (p1 <= mid && num[p1] <= num[p2])) {
            temp[k++] = num[p1++];
        } else {
            temp[k++] = num[p2++];
        }
    }
    memcpy(num + l, temp, sizeof(int) * (r - l + 1));
    free(temp);
    return;
}

void randint(int *arr, int n) {
    while(n--) arr[n] = rand() % 100;
    return;
}

void output(int *num, int n) {
    printf("[");
    for(int i = 0 ; i < n; i++) {
        printf("%d ", num[i]);
    }
    printf("]\n");
}

int main() {
    srand(time(0));
    #define max_op 20
    int arr[max_op];
    randint(arr, max_op);
    TEST(arr, max_op, insert, num, max_op);
    TEST(arr, max_op, bubble_sort, num, max_op);
    TEST(arr, max_op, merge_sort, num, 0, max_op - 1);
    return 0;
}
