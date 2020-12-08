#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct Node{
    char data;
    struct Node *lchild, *rchild;
}Node;
Node *getNewNode(char val) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = val;
    p->lchild = NULL;
    p->rchild = NULL;
    return p;
}
void output(Node *root) {
    if(root == NULL) return;
    printf("%c", root->data);
    if(root->lchild == NULL && root->rchild == NULL) return;
    printf("(");
    if(root->lchild) {
    output(root->lchild);
    }
    if(root->rchild) {
    printf(",");
    output(root->rchild);
    }
    printf(")");
    return;
}

void clear_Node(Node *node) {
    if(node == NULL) return;
    clear_Node(node->lchild);
    clear_Node(node->rchild);
    return ;
}
char str[100][10];
int k = 0;

Node *search(Node *node, char val) {
    if(node->data == val)return node;
    if(node->lchild && node->lchild->data == val) {
        return node->lchild;
    } else if(node->lchild){
        search(node->lchild, val);
    }
    if(node->rchild && node->rchild->data == val) {
        return node->rchild;
    } else if(node->rchild) {
        search(node->rchild, val);
    }
}
Node *build(Node *node,  int i) {
              if(str[i][0] == '^') {
                    Node *root = getNewNode(str[i][1]);
                    return root;
               } else  {
                  if(str[i][2] == 'L') {
                    Node *temp = search(node, str[i][0]);
                    temp->lchild = getNewNode(str[i][1]);
                  }
                 if(str[i][2] == 'R'){
                    Node *temp = search(node, str[i][0]);
                    temp->rchild = getNewNode(str[i][1]);
                  }
              }     
    return node;
}


int main() {
    Node *root = NULL;
       for(int i = 1;; i++) {
           scanf("%s", str[i]);
           k++;
           if(str[i][0] == '^'&& str[i][1] == '^') {
               break;
           }
       }
      for(int i = 1; i < k; i++) {
          root = build(root, i);
       }
        output(root);
        printf("\n");
        clear_Node(root);
    return 0;
}
