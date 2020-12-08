#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define OK 1

typedef struct Vector {
    int size, length;
    int *data;
} Vector;

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
    for(int i = vector->length; i > loc; i--) {
        vector->data[i] = vector->data[i - 1];
    }
    vector->data[loc] = value;
    vector->length++;
    return OK;
}

int search(Vector *vector, int value) {
    for(int i = 0; i < vector->length;i ++) {
        if(vector->data[i] == value) {
            return i;
        }
    }
    return -1;
}

int delete_node(Vector *vector, int index) {
    if(index < 0 || index >= vector->length) {
        return ERROR;
    }
    for(int i = index + 1; i < vector->length; i++) {
        vector->data[i - 1] = vector->data[i];
    }
    vector->length--;
    return OK;
}

void print(Vector *vector) {
    for(int i = 0; i < vector->length; i++) {
        if(i > 0) printf(" ");
        printf("%d", vector->data[i]);
    }
    printf("\n");
}

void clear(Vector *vector) {
     free(vector->data);
     free(vector);
}

int main() {
    Vector *a = (Vector *)malloc(sizeof(Vector));
    init(a, 20);
    int n;
    scanf("%d", &n);
    int t = 0;
    while(n --) {
        scanf("%d", &t);
        if(t == 1) {
            int c, d;
            scanf("%d%d", &c,&d);
            int w = insert(a, c, d);
            if(w == OK)printf("success\n");
            else {
                printf("failed\n");
            }
        } else if(t == 2) {
            int c;
            scanf("%d", &c);
            int w = delete_node(a, c);
            if(w == OK) {
                printf("success\n");
            } else {
                printf("failed\n");
            }
        } else if(t == 3) {
            int c;
            scanf("%d", &c);
            int w = search(a, c);
            if(w == -1) {
                printf("failed\n");
            } else {
                printf("success\n");
            }
        } else if(t == 4) {
            print(a);
        }
    }
    clear(a);
    return 0;
}
