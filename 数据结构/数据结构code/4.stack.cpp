/*************************************************************************
	> File Name: 4.stack.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年02月13日 星期四 20时14分23秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct Stack{
    int *data;
    int top, size;
}Stack;

Stack *init(int n) {
    Stack *s = (Stack *) malloc(sizeof(Stack));
    s->data = (int *)malloc(sizeof(int) * n);
    s->top = -1;
    s->size = n;
    return s;
}


int empty(Stack *s) {
    return s->top == -1;
}

int top(Stack *s) {
    return s->data[s->top];
}
/*
int expand(Stack *s) {
    int *p_data = s->data;
    s->size *= 2;
    s->data = (int *)malloc(sizeof(int) * s->size);
    for(int i = 0; i < s->size; i++) {

    }
}
*/
int expand(Stack *s) {
    int extr_size = s->size;
    int *p;
    while(extr_size) {
        p = (int *) realloc(s->data, sizeof(int) * (s->size + extr_size));
        if(p) break;
        extr_size /= 2;
    }
    if(p == NULL) return 0;
    s->size += extr_size;
    s->data = p;
    return 1;
}


int push(Stack *s, int val) {
    if(s == NULL) return 0;
    if(s->top + 1 == s->size) {
        if(!expand(s)) return 0;
        printf("expand successful size = %d\n", s->size);
    }
    s->data[++(s->top)] = val;
    return 1;
}

int pop(Stack *s) {
    if(s == NULL) return 0;
    if(empty(s))return 0;
    s->top -= 1;
    return 1;
}

void output(Stack *s) {
    printf("Stack(%d) = [", s->top + 1);
    for(int i = 0; i <= s->top; i++) {
        i && printf(", ");
        printf("%d", s->data[i]);
    }
    printf("]\n");
    return;
}

void clear(Stack *s) {
    if(s == NULL) return ;
    free(s->data);
    free(s);
    return;
}

int main() {
    srand(time(0));
    #define max_op 20
    int op, val;
    Stack *s = init(max_op);
    for(int i = 0; i < max_op; i++) {
        op = rand() % 4;
        val = rand() % 100;
        switch(op) {
            case 0:
            case 1:
            case 2:{
                printf("push %d to Stack = %d\n", val, push(s, val));
            } break;
            case 3:{
                printf("pop %d from Stack = ", top(s));
                printf("%d\n", pop(s));
            }break;
        }
        output(s);
        printf("\n");
    }
    clear(s);
    return 0;
}
