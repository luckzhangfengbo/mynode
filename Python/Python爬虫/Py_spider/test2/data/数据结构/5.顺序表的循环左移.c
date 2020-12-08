#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
typedef struct{
    int size, length;
    int *data;
}Vector;
void init(Vector *vector, int size) {
    vector->size = size;
    vector->length = 0;
    vector->data = (int *)malloc(sizeof(int)*size);
}
void expand(Vector *vector) {
    int *old_data = vector->data;
    vector->size =vector->size * 2;
    vector->data = (int *)malloc(sizeof(int)*vector->size);
    for(int i = 0; i < vector->length; i++) {
        vector->data[i] = old_data[i];
    }
    free(old_data);
}
int insert(Vector *vector, int loc ,int value) {
    if(loc < 0 || loc > vector->length) {
        return ERROR;
    }
    if(vector->length >= vector->size) {
        expand(vector);
    }
    for(int i = vector->length; i > loc ; i--) {
        vector->data[i] = vector->data[i - 1];
    }
    vector->data[loc] = value;
    vector->length++;
    return OK;
}
void print(Vector *vector, int n) {
    if(n == 0) {
        printf("%d\n", vector->data[0]);
        return;
    }
    for(int i = n; i < vector->length; i++) {
        printf("%d ",vector->data[i]);
    }
    for(int i = 0; i < n - 1; i++) {
        printf("%d ", vector->data[i]);
    }
    printf("%d\n", vector->data[n - 1]);
}
int main() {
    Vector *a = (Vector *)malloc(sizeof(Vector));
    init(a, 101);
    int m, n;
    scanf("%d%d", &n,&m);
    int w;
    for(int i = 0; i < n; i++) {
        scanf("%d",&w);
        insert(a, i, w);
    }
    print(a, m);
    return 0;
}
