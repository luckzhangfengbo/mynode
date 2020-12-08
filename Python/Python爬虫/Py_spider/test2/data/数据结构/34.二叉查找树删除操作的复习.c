#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define OK 1

typedef struct Node {
    int data;
    struct Node *lchild, *rchild, *father;
}Node;

Node* init(int _data, Node *_father) {
    Node *node =(Node *)malloc(sizeof(Node));
    node->data = _data;
    node->lchild = NULL;
    node->rchild = NULL;
    node->father = _father;
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
    if (node == NULL || node->data == value) {
        return node;
    } else if (value > node->data) {
        if (node->rchild == NULL) {
            return NULL;
        } else {
            return search(node->rchild, value);
        }
    } else {
        if (node->lchild == NULL) {
            return NULL;
        } else {
            return search(node->lchild, value);
        }
    }
}

Node* predecessor(Node *node) {
   Node *temp = node->lchild;
    while (temp != NULL && temp->rchild != NULL) {
        temp = temp->rchild;
    }
    return temp;
}
Node* successor(Node *node) {
    Node *temp = node->rchild;
    while (temp != NULL && temp->lchild != NULL) {
        temp = temp->lchild;
    }
    return temp;
}

void remove_node(Node *delete_node) {
    Node *temp = NULL;
    if (delete_node->lchild != NULL) {
        temp = delete_node->lchild;
        temp->father = delete_node->father;
    }
    if (delete_node->rchild != NULL) {
        temp = delete_node->rchild;
        temp->father = delete_node->father;
    }
    if (delete_node->father->lchild == delete_node) {
        delete_node->father->lchild = temp;
    } else {
        delete_node->father->rchild = temp;
    }
    delete_node->lchild = NULL;
    delete_node->rchild = NULL;
    free(delete_node);
}

int delete_tree(Node *node, int value) {
    Node *delete_node, *current_node;
    current_node = search(node, value);
    if(current_node == NULL) {
        return ERROR;
    }
    if(current_node->lchild!= NULL) {
    delete_node = predecessor(current_node);
    } else if(current_node->rchild!= NULL) {
    delete_node = successor(current_node);
    } else {
    delete_node = current_node;
    }
    current_node->data = delete_node->data;
    remove_node(delete_node);
    return OK;
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
    int n, t;
    Node *binarytree = NULL;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &t) ;
        binarytree = insert(binarytree, t);
    }
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d", &t);
        delete_tree(binarytree, t);
    }
    output(binarytree);
    clear(binarytree);
    return 0;
}
