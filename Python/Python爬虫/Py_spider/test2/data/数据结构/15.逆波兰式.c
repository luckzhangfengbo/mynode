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

int precede(char a, char b) {
    int rank_a, rank_b;
    if (a == '+' || a == '-') {
        rank_a = 1;
    } else {
        rank_a = 2;
    }
    if (b == '+' || b == '-') {
        rank_b = 1;
    } else {
        rank_b = 2;
    }
    return rank_a > rank_b;
}
int operate(char w, int a, int b) {
   switch (w) {
        case '+' : return a + b;
        case '-' : return b - a;
        case '*' : return a * b;
        case '/' : return b / a;
    }
    return 0;
}
void calc(Stack *numbers, Stack *operators) {
    int a, b;
    a = top(numbers);
    pop(numbers);
    b = top(numbers);
    pop(numbers);
    push(numbers, operate(top(operators), a, b));
    pop(operators);
}

void clear(Stack *s) {
    free(s->data);
    free(s);
}

int main() {
    int n;
    Stack *num = (Stack *)malloc(sizeof(Stack));
    Stack *opr = (Stack *)malloc(sizeof(Stack));
    n = 20;
    init(num, n);
    init(opr, n);
    char *buffer = (char *)malloc(n + 1);
    scanf("%s", buffer);
    for (int i = 0; i < strlen(buffer); i++) {
        if (isdigit(buffer[i])) {
            push(num, buffer[i] - '0');
        } else {
            while (!empty(opr) && !precede(buffer[i], top(opr))) {
            calc(num, opr);
            }
            push(opr, buffer[i]);
        }
    }
    while (!empty(opr)) {
        calc(num, opr);
    }
    printf("%d\n", top(num));
    clear(num);
    clear(opr);
    free(buffer);
return 0;
}
