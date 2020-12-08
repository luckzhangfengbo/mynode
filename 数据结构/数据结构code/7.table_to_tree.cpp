/*************************************************************************
	> File Name: 7.table_to_tree.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年02月15日 星期六 20时31分41秒
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node {
    char data;
    struct Node *lchild, *rchild;
}Node;

typedef struct Tree {
    Node *root;
    int n;
}Tree;

typedef struct Stack {
    Node **data; /*Stack此处应该是Node *类型*/
    int top, size;
} Stack;


Node *getNewNode(char val) { /* 获取一个新的结点*/
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = val;
    p->lchild = p->rchild = NULL;
    return p;
}

Tree *getNewTree() {  
    /* 获取一个新的树*/
    Tree *tree = (Tree *)malloc(sizeof(Tree));
    tree->root = NULL;
    tree->n = 0;
    return tree;
}

Stack *init_stack(int n){ //初始化一个栈
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = (Node **)malloc(sizeof(Node *) * n); // 开辟数据的长度为ｎ的大小个，结点类型的
    s->top = -1;// 初始化栈顶都为-１
    s->size = n;
    return s;
}

int empty(Stack *s) { //判断一个栈是否为空
    return s->top == -1; 
}

Node *top(Stack *s) {// 返回栈顶元素，返回类型为Node *类型，为结点类型
    return s->data[s->top];
}

int push(Stack *s, Node *val) { // 结点入栈操作,此处为Node *val
    if(s == NULL) return 0;
    if(s->top == s->size - 1) return 0;
    s->data[++(s->top)] = val;
    return 1;
}

int pop(Stack *s) { //删除栈顶操作
    if(empty(s)) return 0;
    s->top -= 1;
    return 1;
}
void clear_stack(Stack *s); 
Node *build(char *str, int *node_num) { //建立二叉树，由广义表转二叉树
    Node *temp = NULL, *p = NULL; //定义两个结点
    Stack *s = init_stack(strlen(str));// 初始化一个栈大小为字符串长度
    int flag = 0; //标记，如果遇到“，”则为１，告诉下面是左还是右子树
    while(str[0]) {
        switch(str[0]) { //如果不是\n继续往后遍历
            case '(' :   
                   push(s, temp);//如果遇到（将入栈
                   flag = 0;
                   temp = NULL;//将temp置空
                   break;
            case ')' :
                   p = top(s); //如果遇到）时出栈
                   pop(s);
                   break;
            case ',' :
                   flag = 1; //遇到“，”标记，将temp＝ＮＵＬＬ；
                   temp = NULL; //告诉下面右子树为空
                   break;
            case ' ' :
                   break;
            default  : // 如果是字母
                   temp = getNewNode(str[0]);//获取一个节点
                   if(!empty(s)&& flag == 0){ //如果栈不为空，并且为左子树
                   top(s) ->lchild = temp; 
                   } else if(!empty(s)&&flag == 1) { //如果栈不为空，并且为右子树，
                   top(s) ->rchild = temp;
                   }
                   ++(*node_num);//创建一个成功后记录个数
            break;
        }
        ++str; // str往后移动
    }
    clear_stack(s); //清空栈
    if(temp && !p) p = temp;// temp 不为空，p为空,将p = temp;
    return p; //返回p，p为顶
}

/*中序遍历*/
void in_orderNode(Node *node) {
    if(node == NULL) return;
    in_orderNode(node->lchild);
    printf("%c ", node->data);
    in_orderNode(node->rchild);
    return;
}

void in_order(Tree *tree) {
    printf("in_order : ");
    in_orderNode(tree->root);
    return;
}
/*前序遍历*/
void pre_orderNode(Node *node) {
    if(node == NULL) return;
    printf("%c ", node->data);
    pre_orderNode(node->lchild);
    pre_orderNode(node->rchild);
    return;
}

void pre_order(Tree *tree) {
    printf("pre_order : ");
    pre_orderNode(tree->root);
    return;
}
/*后序遍历*/
void post_orderNode(Node *node) {
    if(node == NULL) return;
    post_orderNode(node->lchild);
    post_orderNode(node->rchild);
    printf("%c ",node->data);
    return;
}

void post_order(Tree *tree) {
    printf("post_order : ");
    post_orderNode(tree->root);
    return;
}




void clear_node(Node *node) {
    if(node == NULL) return ;
    clear_node(node->lchild);
    clear_node(node->rchild);
    return;
}


void clear_tree(Tree *tree) {
    if(tree == NULL) return;
    clear_node(tree->root);
    free(tree);
    return ;
}

void clear_stack(Stack *s) {
    if(s == NULL) return ;
    free(s->data);
    free(s);
    return;
}

int main() {
    char str[100];
    scanf("%[^\n]s", str);
    int node_num = 0;
    Tree *tree = getNewTree();
    tree->root = build(str, &node_num);
    tree->n = node_num;
    pre_order(tree), printf("\n");
    in_order(tree), printf("\n");
    post_order(tree), printf("\n");
    clear_tree(tree);
    return 0;
}
