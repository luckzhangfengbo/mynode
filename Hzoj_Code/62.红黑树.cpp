/*************************************************************************
	> File Name: A.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年05月30日 星期六 14时43分09秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
#define RED 0
#define BLACK 1
#define DOUBLE_BLACK 2
typedef struct Node {
    int key, color;
    struct Node *lchild, *rchild;
}Node;

Node __NIL;
#define NIL (&__NIL)
__attribute__((constructor))
void init_NIL() {
    NIL->key = 0;
    NIL->lchild = NIL->rchild = NIL;
    NIL->color = BLACK;
    return;
}

Node *getNewNode(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->color = RED;
    p->lchild = p->rchild = NIL;
    return p;
}
int hashRedChild(Node *root) {
    return root->lchild->color == RED || root->rchild->color == RED;
}


Node *right_rotate(Node *root) {
    Node *temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    return temp;
}
Node *left_rotate(Node *root) {
    Node *temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    return temp;
}

Node *insert__maintain(Node *root) {
    if(!hashRedChild(root)) return root;
    if(root->lchild->color == RED && root->rchild->color == RED) {
        if(!hashRedChild(root->lchild) && !hashRedChild(root->rchild)) return root;
        goto insert_end;
    }
    if(root->lchild->color == RED) {
        if(!hashRedChild(root->lchild)) return root;
        if(root->lchild->rchild->color == RED) {
            root->lchild = left_rotate(root->lchild);
        }
        root = right_rotate(root);
    } else {
        if(!hashRedChild(root->rchild)) return root;
        if(root->rchild->lchild->color == RED) {
            root->rchild = right_rotate(root->rchild);
        }
        root = left_rotate(root);        
    }
    insert_end:
    root->color = RED;
    root->lchild->color = root->rchild->color = BLACK;
    return root;
}


Node *__insert(Node *root, int key) {
    if(root == NIL) return getNewNode(key);
    if(root->key == key) return root;
    if(root->key > key) {
        root->lchild = __insert(root->lchild, key);
    } else {
        root->rchild = __insert(root->rchild, key);
    }
    return insert__maintain(root);
}

Node *insert(Node *root, int key) {
    root = __insert(root, key);
    root->color = BLACK;
    return root;
}

Node *predecceddor(Node *root) {
    Node *temp = root->lchild;
    while(temp->rchild != NIL) temp = temp->rchild;
    return temp;
}


Node *erase__maintain(Node *root) {
    if(root->lchild->color != DOUBLE_BLACK && root->rchild->color != DOUBLE_BLACK) {
        return root;
    }
    if(hashRedChild(root)) {
        root->color = RED;
        if(root->lchild->color == RED) {
            root = right_rotate(root);
            root->rchild = erase__maintain(root->rchild);
        } else {
            root = left_rotate(root);
            root->lchild = erase__maintain(root->lchild);
        }
        root->color = BLACK;
        return root;
    }
    if((root->lchild->color == DOUBLE_BLACK && !hashRedChild(root->rchild)) ||
       (root->rchild->color == DOUBLE_BLACK && !hashRedChild(root->lchild))) {
           root->color += 1;
           root->lchild->color -= 1;
           root->rchild->color -= 1;
           return root;
    }
    if(root->rchild->color == BLACK) {
        if(root->rchild->rchild->color!=RED) {
            root->rchild->color = RED;
            root->rchild = right_rotate(root->rchild);
            root->rchild->color = BLACK;
        }
        root->rchild->color = root->color;
        root->color = BLACK;
        root->lchild->color -= 1;
        root = left_rotate(root);
        root->rchild->color = BLACK;
    } else {
        if(root->lchild->lchild->color!=RED) {
            root->lchild->color = RED;
            root->lchild = left_rotate(root->lchild);
            root->lchild->color = BLACK;
        }
        root->lchild->color = root->color;
        root->color = BLACK;
        root->rchild->color -= 1;
        root = right_rotate(root);
        root->lchild->color = BLACK;        
    }
    return root;
}


Node *__erase(Node *root, int key) {
    if(root == NIL) return root;
    if(root->key > key) {
        root->lchild = __erase(root->lchild, key);
    } else if(root->key < key) {
        root->rchild = __erase(root->rchild, key);
    } else {
        if(root->lchild == NIL || root->rchild == NIL) {
            Node *temp = (root->lchild == NIL ? root->rchild : root->lchild);
            temp->color += root->color;
            free(root);
            return temp;
        } else {
            Node *temp = predecceddor(root);
            root->key = temp->key;
            root->lchild = __erase(root->lchild, temp->key);
        }
    }
    return erase__maintain(root);
}

Node *erase(Node *root, int key) {
    root = __erase(root, key);
    root->color = BLACK;
    return root;
}

void output(Node *root) {
    if(root == NIL) return;
    output(root->lchild);
    printf("%d %d %d %d\n", root->key, root->color, root->lchild->key, root->rchild->key);
    output(root->rchild);
    return;
}

int main() {
    int t, val;
    Node *root = NIL;
    while(~scanf("%d%d", &t, &val)) {
        switch(t) {
            case 1 : root = insert(root, val);break;
            case 2 : root = erase(root, val);break;
            case 3 : output(root);break;
        }
    }
    return 0;
}
