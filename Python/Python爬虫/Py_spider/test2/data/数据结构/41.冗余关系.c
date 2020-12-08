/*#include<stdio.h>
#include<stdlib.h>
#define swap(a, b) {\
__typeof(a) __temp = a;\
a = b; b = __temp;\
}

int max(int a, int b) {
    return a > b ? a : b;
}
typedef struct DisjointSet {
    int *father, *rank;
}DisjointSet;

void init(DisjointSet *s, int size) {
    s->father = (int *)malloc(sizeof(int) * size);
    s->rank = (int *)malloc(sizeof(int) * size);
    for(int i = 1; i <= size; i++) {
        s->father[i] = i;
        s->rank[i] = 1;
    }
}

int find_set(DisjointSet *s, int node) {
    if(s->father[node] != node) {
        s->father[node] = find_set(s, s->father[node]);
    }
    return s->father[node];
}

int merge(DisjointSet *s, int a, int b) {
    int fa = find_set(s, a);
    int fb = find_set(s, b);
    if(fa != fb) {
        if(s->rank[fa] > s->rank[fb]) {
            swap(fa, fb);
        }
        s->father[fa] = fb;
        s->rank[fb] = max(s->rank[fb], s->rank[fa] + 1);
        return 1;
    }
    return 0;
}

void clear(DisjointSet *s) {
    free(s->father);
    free(s->rank);
    free(s);
}

int main() {
    DisjointSet *s = (DisjointSet *)malloc(sizeof(DisjointSet));
    int n, m;
    scanf("%d%d", &n, &m);
    init(s, n);
    int sum = 0;
    while(m--) {
        int x, y;
        scanf("%d%d", &x, &y);
        if(!merge(s, x, y)){
            sum++;
        }
    }
    printf("%d\n", sum);
}
*/
#include<stdio.h>
int p[1500], size[1500];
int find(int x) {
    if(p[x] != x)p[x] = find(p[x]);
    return p[x];
}

int merge(int a, int b) {
    int fa = find(a), fb = find(b);
    if(fa != fb) {
        p[fa] = fb;
        size[fb] += size[fa];
        return 1;
    } 
    return 0;
}

void init(int n) {
    for(int i = 1; i <= n; i++) {
        p[i] = i;
        size[i] = 1;
    }
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    init(n);
    int sum = 0;
    while(m--) {
        int x, y;
        scanf("%d%d", &x, &y);
        if(!merge(x, y)){
            sum++;
        }
    }
    printf("%d\n", sum);
    return 0;
}
