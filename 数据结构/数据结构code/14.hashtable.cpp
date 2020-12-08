/*************************************************************************
	> File Name: 14.hashtable.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年02月22日 星期六 15时03分41秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node {
    char *str;
    struct Node *next;
}Node;

typedef struct HashTable {
    Node **data;
    int size;
}HashTable;

Node *init_node(char *str, Node *head) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->str = strdup(str);
    p->next = head;
    return p;
}

HashTable *init_hashtable(int n) {
    HashTable *h = (HashTable *)malloc(sizeof(HashTable));
    h->size = n << 1;
    h->data = (Node **)calloc(h->size, sizeof(Node *));//清地址
/*calloc
为 num 个对象的数组分配内存，并初始化所有分配存储中的字节为零。
若分配成功，会返回指向分配内存块最低位（首位）字节的指针，它为任何类型适当地对齐。
若 size 为零，则行为是实现定义的（可返回空指针，或返回不可用于访问存储的非空指针）。
https://zh.cppreference.com/w/c/memory/calloc
*/
    return h;
}

int BKDRHash(char *str) {
    int seed = 31, hash = 0;
    for(int i = 0; str[i]; i++) hash = hash * seed + str[i];
    return hash & 0x7fffffff;
}

int insert(HashTable *h, char *str) {
    int hash = BKDRHash(str);
    int ind = hash % h->size;
    h->data[ind] = init_node(str, h->data[ind]);
    return 1;
}

int search(HashTable *h, char *str) {
    int hash = BKDRHash(str);
    int ind = hash % h->size;
    Node *p = h->data[ind];
    while(p && strcmp(p->str, str))p = p->next;
    return p != NULL;
}


void clear_node(Node *node) {
    if(node == NULL) return;
    Node *p = node, *q;
    while(p) {
        q = p->next;
        free(p->str);
        free(p);
        p = q;
    }
    free(q);
    return;
}


void clear_hashtablie(HashTable *h) {
    if(h == NULL) return;
    for(int i = 0; i < h->size; i++) clear_node(h->data[i]);
    free(h->data);
    free(h);
    return;
}

int main() {
    int op;
    #define max_n 100
    char str[max_n + 5];
    HashTable *h = init_hashtable(max_n + 5);
    while(~scanf("%d%s", &op, str)) {
        switch(op) {
            case 0:
            printf("insert %s to hash table\n", str);
            insert(h, str);
            break;
            case 1:
            printf("search %s from hash table tesult = %d\n", str, search(h, str));
            break;
        }
    }
    clear_hashtablie(h);
    return 0;
}
