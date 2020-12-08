#include <stdio.h>
#include <stdlib.h>

typedef struct Heap {
    int *data, size;
} Heap;

void init(Heap *h, int length_input) {
    h->data = (int *)malloc(sizeof(int) * length_input);
    h->size = 0;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void push(Heap *h, int value) {
    h->data[h->size] = value;
    int current = h->size;
    int father = (current - 1) / 2;
    while(h->data[current] > h->data[father]) {
        swap(&h->data[current] , &h->data[father]);
        current = father;
        father = (current - 1) / 2;
    }
    h->size++;
}

void output(Heap *h) {
    for(int i = 0; i < h->size; i++) {
        printf("%d ", h->data[i]);
    }
    printf("\n");
}

int top(Heap *h) {
    return h->data[0];
}

void update(Heap *h, int pos, int n) {
    int lchild = 2 * pos + 1, rchild = 2 * pos + 2;
    int max_pos = pos;
    if(lchild < n&&h->data[max_pos] < h->data[lchild]) {
        max_pos = lchild;
    }
    if(rchild < n&&h->data[max_pos] < h->data[rchild]) {
        max_pos = rchild;
    }
    if(max_pos != pos) {
        swap(&h->data[max_pos], &h->data[pos]);
        update(h, max_pos , n);
    }
}

void pop(Heap *h) {
    swap(&h->data[0], &h->data[h->size - 1]);
    h->size --;
    update(h, 0, h->size);
    return ;
}

void heap_sort(Heap *h) {
    for(int i = h->size - 1; i >= 1; i--) {
        swap(&h->data[i], &h->data[0]);
        update(h, 0, i);
    }
    return;
}

void clear(Heap *h) {
    free(h->data);
    free(h);
    return;
}

int main() {
    int n, w, s;
    Heap *h = (Heap *)malloc(sizeof(Heap));
    init(h, 101);
    scanf("%d", &n);
    for(int i = 0; i < n; i ++) {
        scanf("%d", &w);
        push(h, w);
    }
    scanf("%d", &s);
    for(int i = 1; i <= s; i++) {
    printf("%d\n", top(h));
    pop(h);
    }
    output(h);
    heap_sort(h);
    output(h);
    return 0;
}
