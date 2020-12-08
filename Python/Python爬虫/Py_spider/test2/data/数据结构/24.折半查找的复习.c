#include <stdio.h>

int search(int *data, int length, int value) {
     int left = 0, right = length - 1;
     int sum = 0;
     while(left <= right) {
         sum ++;
        int mid = (left + right) / 2;
        if(data[mid] == value) {
            printf("%d ", sum);
            return mid;
        } else if(data[mid] < value){
            left = mid + 1;
        } else {
            right = mid -1;
        }
    }
    printf("%d ", sum);
    return -1;
}

int main() {
    int data[101];
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d ", &data[i] );
    }
    int m, w = 0;
    scanf("%d", &m);
    while(m--) {
        scanf("%d ", &w);
        int s = search(data, n, w);
        if( s == -1) {
            printf("failed\n");
        } else {
            printf("success\n");
        }
    }
    return 0;
}
