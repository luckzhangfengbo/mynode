#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
typedef struct Vector{
    int size, length;
    int *data;
}Vector;

void init(Vector *vector, int size) {
    vector->size = size;
    vector->length = 0;
    vector->data = (int *)malloc(sizeof(int) * size);
}
void expand(Vector *vector) {
    int *old_data = vector->data;
    vector->size = vector->size * 2;
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
void print(Vector *vectora, Vector *vectorb, Vector *vectorc) {
    int k = 0;
    for(int i = 0; i < vectora->length; i++) {
        for(int j = 0; j < vectorb->length; j++) {
            if(vectora->data[i] == vectorb->data[j]) {
                 insert(vectorc, k++, vectora->data[i]);
     //       printf("%d ", vectora->data[i]);
            }
        }
    }
    
}
void print1(Vector *vector) {
    if(vector->length == 0) {
        printf("%d\n", vector->length);
        return;
    } else {
        printf("%d\n", vector->length);
    }
    for(int i = 0; i < vector->length - 1; i++) {
        printf("%d ", vector->data[i]);
    }
    printf("%d\n", vector->data[vector->length - 1]);
}
int main() {
    Vector *a = (Vector *)malloc(sizeof(Vector));
    Vector *b = (Vector *)malloc(sizeof(Vector));
    Vector *c = (Vector *)malloc(sizeof(Vector));
    int n, m;
    init(a, 55);
    init(b, 55);
    init(c, 55);
    scanf("%d", &n);
    int w = 0;
    for(int i = 0; i < n; i++) {
        scanf("%d", &w);
        insert(a, i, w);
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        scanf("%d", &w);
        insert(b, i, w);
    }
    print(a, b, c);
    print1(c);
    return 0;
}
