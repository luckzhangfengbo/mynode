#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;
    struct Node *prior;
}Node, *LinkedList;

Node insert(LinkedList head, int index, int value) {
    Node *current_node, ret;
    int raw_index = index, len = 0;
    current_node = head;
    ret.data = 0;
    while(current_node && index) {
        current_node = current_node -> next;
        --index;
        ++len;
        if(current_node == head) break;
    }
    if(index ==  0) {
        Node *node = (Node *)malloc(sizeof(Node));
        node->data = value;
        node->next = node;
        if(current_node != NULL) {
            node->next = current_node->next;
            current_node->next = node;
        }
        node->prior = NULL;
        if(current_node == head && len == raw_index) {
            head = node;
        }
        ret.data = 1;
     }
    ret.next = head;
    return ret;
}
LinkedList build(LinkedList head) {
    Node *current_node, *next_node;
    if(head == NULL)  {
        return head;
    }
    current_node = head;
    next_node =  head -> next;
    do {
        next_node->prior = current_node;
        current_node = current_node->next;
        next_node = next_node->next;
    } while(next_node != head->next);
    return head;
}
void output(LinkedList head, int m) {
    int len = 0;
    Node *current_node = head, *next_node;
    while(current_node->data != m) {
        current_node = current_node->next;
    }
    next_node = current_node;
    printf("%d", current_node->data);
    current_node = current_node -> prior;
    while(current_node!= next_node) {
        printf(" %d", current_node->data);
        current_node = current_node -> prior;
    }
    printf("\n");
    return;
}
void clear(LinkedList head) {
    Node *current_node, *next_node;
    if(head == NULL) {
        return;
    }
    current_node = head->next;
    head->next = NULL;
    while(current_node) {
        next_node = current_node->next;
        free(current_node);
        current_node = next_node;
    }
    return;
}

int main() {
    LinkedList linkedlist = NULL;
    Node ret;
    int n, m, num;
    scanf("%d", &n);
    for(int i = 0; i < n ; i++) {
        scanf("%d", &num);
        ret = insert(linkedlist, i, num);
        if(ret.data == 0) {
        printf("ERROR\n");
            return 1;
        }
        linkedlist = ret.next;
    }
    linkedlist = build(linkedlist);
    scanf("%d", &m);
    output(linkedlist, m);
    clear(linkedlist);
    return 0;
}
