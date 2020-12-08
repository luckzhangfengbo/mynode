#include <stdio.h>

int search(int *data, int length, int value) {
    int sum = 0;    
    for(int i = 0; i < length; i++) {
        sum ++;
        if(data[i] == value){
            printf("%d ",sum);
            return i;
        }  else if(data[i] > value) {
            printf("%d ", sum);
            return -1;
        }
    }
    printf("%d ", length);
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
            printf("%d\n", s);
        }
    }
    return 0;
}
