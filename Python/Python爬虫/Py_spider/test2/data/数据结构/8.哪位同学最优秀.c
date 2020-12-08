#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;
}Node, *LinkedList;

void clear(LinkedList head) {
    Node *current_node = head;
    while(current_node != NULL) {
        Node *delete_node = current_node;
        current_node = current_node->next;
        free(delete_node);
    }
}
LinkedList insert(LinkedList head, Node *node, int index) {
    if(head == NULL) {
        if(index != 0) {
            return head;
        }
        head = node;
        return head;
    }
    if(index == 0) {
        node->next = head;
        head = node;
        return head;
    }
    Node *current_node = head;
    int count = 0;
    while(current_node->next != NULL && count < index - 1) {
        current_node = current_node->next;
        count++;
    }
    if(count == index - 1) {
        node->next = current_node->next;
        current_node->next = node;
    }
    return head;
}
LinkedList delete_node(LinkedList head, int index) {
    if(head == NULL) {
        return head;
    }
    if(index == 0) {
        Node *delete_node = head;
        head = head->next;
        free(delete_node);
    }
    Node *current_node = head;
    int count = 0;
    while(current_node->next != NULL && count < index - 1) {
        current_node = current_node->next;
        count ++;
    }
    if(count == index - 1 && current_node->next != NULL) {
        Node *delete_node = current_node->next;
        current_node ->next = delete_node->next;
        free(delete_node);
    }
    return head;
}
void output(LinkedList head) {
    if(head == NULL) {
        return;
    }
    Node *current_node = head;
    int sum = 0;
    while(current_node != NULL) {
       // printf("%d ",current_node->data);
        current_node = current_node->next;
        sum++;
    }
    Node *current_node2 = head;
    int num = 0;
    while(current_node2->next != NULL && num < sum / 2) {
        current_node2 = current_node2->next;
        num++;
    }
    printf("%d\n", current_node2->data);
}
int main() {
    LinkedList linkedlist = NULL;
    int n, m;
    scanf("%d%d", &n,&m);
    for(int i = 1; i <= n; i++) {
        Node *node = (Node *)malloc(sizeof(Node));
        node->data = i;
        node->next = NULL;
        linkedlist = insert(linkedlist, node, i - 1);
    }
    int s;
    for(int i = 1; i <= m; i++) {
        scanf("%d", &s);
        linkedlist = delete_node(linkedlist, s - 1);
    }
    output(linkedlist);
    return 0;
}
