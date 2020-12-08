#include<stdio.h>
#include<stdlib.h>
#include <string.h>
typedef struct Node {
    char data;
    struct Node *lchild, *rchild;
}Node;

typedef struct Tree {
    Node *root;
    int n;
}Tree;

Node *getNewNode(char val) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = val;
    p->lchild = p->rchild = NULL;
    return p;
}

Tree *getNewTree() {
    Tree *tree = (Tree *)malloc(sizeof(Tree));
    tree->root = NULL;
    tree->n = 0;
}

Node *build(char pre_str[], char in_str[], int len) {
    Node *p = getNewNode(pre_str[0]);
    int pos = strchr(in_str, pre_str[0]) - in_str;
    if(pos > 0) {
        p->lchild = build(pre_str + 1, in_str, pos);
    } 
    if(len - pos - 1 > 0) {
        p->rchild = build(pre_str + pos + 1, in_str + pos + 1, len - pos - 1);
    }
    return p;
}
void post_orderNode(Node *node) {
    if(node == NULL) return;
    post_orderNode(node->lchild);
    post_orderNode(node->rchild);
    printf("%c",node->data);
    return;
}

void post_order(Tree *tree) {
    post_orderNode(tree->root);
    return;
}

void post2_orderNode(Node *node) {
    if(node == NULL) return;
    post2_orderNode(node->rchild);
    post2_orderNode(node->lchild);
    printf("%c",node->data);
    return;
}

void post2_order(Tree *tree) {
    post2_orderNode(tree->root);
    return;
}
void clear_node(Node *node) {
    if(node == NULL) return;
    clear_node(node->lchild);
    clear_node(node->rchild);
    return;
}
void clear_tree(Tree *tree) {
    if(tree == NULL) return;
    clear_node(tree->root);
    free(tree);
    return;
}
int main() {
    char pre_str[50], in_str[50];
    scanf("%s", pre_str);
    scanf("%s", in_str);
    Tree *tree = getNewTree();
    tree->root = build(pre_str, in_str, strlen(pre_str));
    post_order(tree), printf("\n");
    post2_order(tree), printf("\n");
    return 0;
}
