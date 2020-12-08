#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define OK 1
#define ERROR 0
typedef struct Vector{
    int size, length;
    int *data;
    int *temp;
}Vector;
void init(Vector *vector, int size){
    vector->size = size;
    vector->length = 0;
    vector->data = (int *)malloc(sizeof(int)*size);
}
void expand(Vector *vector) {
    vector->size = vector->size * 2;
    int *old_data = vector->data;
    vector->data = (int *)malloc(sizeof(int) * vector->size);
    for(int i = 0; i < vector->length; i++) {
    vector->data[i] = old_data[i];    
    }
    free(old_data);
}
int insert(Vector *vector, int loc, int value) {
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
void print(Vector *vector, Vector *vector1, int x) {
    int sum = 0;
    for(int i = 0; i < vector->length; i++) {
      //  printf("%d %d\n", vector->data[i], vector1->data[i]);
        sum +=  vector->data[i] * pow(x, vector1->data[i]);
    }
    printf("%d\n", sum);
}
int main() {
    Vector *a = (Vector *)malloc(sizeof(Vector));
    Vector *b = (Vector *)malloc(sizeof(Vector));
    init(a, 20);
    init(b, 20);
    int n;
    int c, d;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &c, &d);
        int s = insert(a, i, c);
        int ss = insert(b, i, d);
    }
    int w;
    scanf("%d", &w);
    print(a, b, w);
    return 0;
}
