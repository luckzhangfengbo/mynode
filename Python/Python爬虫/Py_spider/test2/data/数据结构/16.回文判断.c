#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define ERROR 0
#define OK 1

typedef struct Stack {
    int *data;
    int size, top;
} Stack;

void init(Stack *s, int val) {
    s->data = (int*)malloc(sizeof(int) * val);
    s->size = val;
    s->top = -1;
}

int push(Stack *s, int e) {
 if (s->top == s->size - 1) {
        return ERROR;
    }
    s->data[++(s->top)] = e;
    return OK;
}

int pop(Stack *s) {
   if (!empty(s)) {
        --(s->top);
       return OK;
    }
    return ERROR;
}

int top(Stack *s) {
    return s->data[s->top];
}

int empty(Stack *s) {
    return s->top == -1;
}


void clear(Stack *s) {
    free(s->data);
    free(s);
}

int main() {
    char s[30];
    scanf("%[^@]s", s);
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    init(stack, 21);
    for(int i = 0; i < strlen(s); i++) {
        push(stack, s[i]);
    }
    for(int i = 0; i < strlen(s); i++) {
        char w;
        w = top(stack);
        pop(stack);
        if(w != s[i]) {
            printf("false\n");
            return 0;
        }
    }
    printf("true\n");
return 0;
}
