#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int *data;
    struct Node *lchild, *rchild, *father;
}Node;

Node* init( int n, Node *_father) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = n;
    node->father = _father;
    node->lchild = node->rchild = NULL;
    return node;
}

Node* insert(Node *node, int value) {
    if (node == NULL) {
        node = init(value, NULL);
    } else if (value > node->data) {
        if (node->rchild == NULL) {
            node->rchild = init(value, node);
        } else {
            node->rchild = insert(node->rchild, value);
        }
    } else if (value < node->data) {
        if (node->lchild == NULL) {
            node->lchild = init(value, node);
        } else {
            node->lchild = insert(node->lchild, value);
        }
    }
    return node;
}

Node* search(Node *node, int value) {
    if(node->data == value || node == NULL) {
        return node;
    } else if(node->data < value) {
        if(node->rchild == NULL) {
            return NULL;
        } else {
            return search(node->rchild, value);
        }
    } else if(node->data > value) {
        if(node->lchild == NULL) {
            return NULL;
        } else {
            return search(node->lchild, value);
        }
    }
}

void output(Node *node) {
    if(node == NULL) return ;
    if(node->lchild != NULL) {
        output(node->lchild);
    }
    printf("%d ", node->data);
    if(node->rchild != NULL) {
        output(node->rchild);
    }
    return;
}

void clear(Node *node) {
    if (node != NULL) {
        if (node->lchild != NULL) {
            clear(node->lchild);
        }
        if (node->rchild != NULL) {
            clear(node->rchild);
        }
        free(node);
    }
}

int main() {
    Node *binarytree = NULL;
    init(100, binarytree);
    int n, w = 0;
    scanf("%d ", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d ", &w);
        binarytree = insert(binarytree, w);
    }
    int s;
    scanf("%d", &s);
    if(search(binarytree , s)!= NULL) {
        printf("search success!\n");
    } else {
        printf("search failed!\n");
    }
    output(binarytree);
    clear(binarytree);
    return 0;
}
