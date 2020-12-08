#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node{
    char data;
    struct Node *lchild, *rchild;
}Node, *pNode;

pNode init(char val) {
    pNode p = (pNode)malloc(sizeof(Node));
    p->data = val;
    p->lchild = p->rchild = NULL;
    return p;
}

void clear_pNode(pNode node) {
    if(node == NULL) return;
    if(node->lchild != NULL) {
        clear_pNode(node->lchild);
    }
    if(node->rchild != NULL) {
        clear_pNode(node->rchild);
    }
    free(node);
}

void output(pNode root) {
    if(root == NULL) return ;
    printf("%c", root->data);
    if(root->lchild == NULL&&root->rchild== NULL) return;
    printf("(");
    if(root->lchild != NULL) {
        output(root->lchild);
    }
    if(root->rchild != NULL) {
        printf(",");
        output(root->rchild);
    }
    printf(")");
    return;
}

int main() {
    char str[100];
    scanf("%[^$]s", str);
    pNode *p = (pNode *)malloc(sizeof(pNode) * 100);
    int root = 1;
    int len = strlen(str);
    p[root] = NULL;
    for(int i = 0; i < len; i++) {
        if(str[i] == ' ')continue;
        p[root] = init(str[i]);
        if( root != 1) {
            if(root % 2) {
                p[root / 2]->rchild = p[root];
            } else {
                p[root / 2]->lchild = p[root];
            }
        }
        root ++;
    }
    output(p[1]);
    clear_pNode(p[1]);
    free(p);
    return 0;
}
