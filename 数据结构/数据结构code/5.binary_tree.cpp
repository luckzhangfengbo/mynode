/*************************************************************************
	> File Name: 5.binary_tree.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年02月15日 星期六 15时59分51秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct Node{
    int data;
    struct Node *lchild, *rchild;
}Node;
typedef struct Tree {
    Node *root;
    int n;
}Tree;

Node *getNewNode(int val) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = val;
    p->lchild = NULL;
    p->rchild = NULL;
    return p;
}
Tree *getNewTree() {
    Tree *tree = (Tree *)malloc(sizeof(Tree));
    tree->root = NULL;
    tree->n = 0;
    return tree;
}


Node *insertNode(Node *root, int val, int *ret) {
    if(root == NULL){ /*插入成功*/
        *ret = 1;
        return getNewNode(val);
    }
    if(root->data == val) return root; // 插入失败
    if(val < root->data) root->lchild = insertNode(root->lchild,val, ret);
    else root->rchild = insertNode(root->rchild, val, ret);
    return root;
}

void insert(Tree *tree, int val) {
    int flag = 0;
    tree->root = insertNode(tree->root, val, &flag);
    tree->n += flag; // 不知道插入成功还是失败
    return;
}

void outputNode(Node *root) {
    if(root == NULL) return;
    printf("%d", root->data);
    if(root->lchild == NULL && root->rchild == NULL) return;
    printf("(");
    outputNode(root->lchild);
    printf(",");
    outputNode(root->rchild);
    printf(")");
    return;
}
void output(Tree *tree) {
    printf("Tree(%d) = ", tree->n);
    outputNode(tree->root);
    printf("\n");
    return;
}

/*前序遍历*/
void pre_orderNode(Node *root) {
    if(root == NULL) return;
    printf("%d ", root->data);
    pre_orderNode(root->lchild);
    pre_orderNode(root->rchild);
    return;
}


void preorder(Tree *tree) {
    printf("pre_order :");
    pre_orderNode(tree->root);
    printf("\n");
    return;
}

/*中序遍历*/
void in_orderNode(Node *root) {
    if(root == NULL) return;
    in_orderNode(root->lchild);
    printf("%d ", root->data);
    in_orderNode(root->rchild);
    return;
}


void inorder(Tree *tree) {
    printf("in_order :");
    in_orderNode(tree->root);
    printf("\n");
    return;
}

/*后序遍历*/
void post_orderNode(Node *root) {
    if(root == NULL) return;
    post_orderNode(root->lchild);
    post_orderNode(root->rchild);
    printf("%d ", root->data);
    return;
}


void postorder(Tree *tree) {
    printf("post_order :");
    post_orderNode(tree->root);
    printf("\n");
    return;
}


void clear_Node(Node *node) {
    if(node == NULL) return;
    clear_Node(node->lchild);
    clear_Node(node->rchild);
    return ;
}
void clear_Tree(Tree *tree) {
    if(tree == NULL) return;
    clear_Node(tree->root);
    free(tree);
    return;
}

int main() {
    srand(time(0));
    #define max_op 10
    Tree *tree = getNewTree();
    for(int i = 0; i < max_op; i++) {
        int val = rand() % 100;
        insert(tree, val);
        output(tree);
        printf("\n");
    }
    preorder(tree);
    inorder(tree);
    postorder(tree);
    clear_Tree(tree);
    return 0;
}
