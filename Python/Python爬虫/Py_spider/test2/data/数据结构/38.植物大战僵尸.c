#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct Node {
    int ind, f;
}Node;

typedef struct priority_queue{
    Node *data;
    int size, cnt;
}priority_queue;
#define swap(a, b) {\
    __typeof(a) __temp = a;\
    a = b; b = __temp;\
}
priority_queue *init(int n) {
    priority_queue *q = (priority_queue *)malloc(sizeof(priority_queue));
    q->data = (Node *)malloc(sizeof(Node) * (n + 1));
    q->size = n;
    q->cnt = 0;
    return q;
}

int cmp(Node a, Node b) {
    if(a.f > b.f) return 1;
    if(a.f == b.f && a.ind < b.ind) return 1;
    return 0;
}
int empty(priority_queue *q) {
    return q->cnt == 0;
}

Node top(priority_queue *q) {
    return q->data[1];
}

int push(priority_queue *q, Node val) {
    if(q == NULL) return 0;
    if(q->cnt == q->size)return 0;
    q->cnt++;
    q->data[q->cnt] = val;
    int ind = q->cnt;
    while(ind >> 1 && cmp(q->data[ind], q->data[ind >> 1])) {
        swap(q->data[ind], q->data[ind >> 1]);
        ind >>= 1;
    }
    return 1;
}

int pop(priority_queue *q) {
    if(q == NULL) return 0;
    if(empty(q)) return 0;
    q->data[1] = q->data[q->cnt--];
    int ind = 1;
    while((ind << 1) <= q->cnt) {
        int temp = ind, l = ind << 1, r = ind << 1 | 1;
        if(cmp(q->data[l], q->data[temp]))temp = l;
        if(r <= q->cnt && cmp(q->data[r] , q->data[temp])) temp = r;
        if(temp == ind) break;
        swap(q->data[ind], q->data[temp]);
        ind = temp;
    }
    return 1;
}

void clear(priority_queue *q) {
    if(q == NULL) return;
    free(q->data);
    free(q);
    return;
}

int main() {
    int t, num = 0;
    priority_queue *q[101];
    for(int i = 1; i <= 100; i++) {
        q[i] = init(50000);
    }
    int n;
    scanf("%d",&t);
    while(num < t) {
        printf("Case #%d:\n", ++num);
        scanf("%d", &n);
        Node now;
        int s;
        for(int i = 0; i < n; i++) {
            scanf("%d%d", &now.f, &s);
            now.ind = i + 1;
            push(q[s], now);
        }
        for(int i = 0; i < n; i++) {
            int m = -1;
            Node now1, now2;
            for(int j = 1; j <= 100; j++) {
                if(empty(q[j]))continue;
                if(m == -1) {
                    m = j;
                    continue;
                }
                now1 = top(q[m]);
                now2 = top(q[j]);
                now1.f = now1.f + i * m;
                now2.f = now2.f + i * j;
                if(cmp(now2, now1)){
                    m = j;
                }
            }
            printf("%d", top(q[m]).ind);
            pop(q[m]);
            if(i != n - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
    for(int i = 1; i <= 100; i++) {
        clear(q[i]);
    }
    return 0;
}
