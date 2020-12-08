#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node {
    char data;
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
LinkedList reverse(LinkedList head) {
    if(head == NULL) {
        return head;
    }
    Node *current_node, *next_node;
    current_node = head->next;
    head->next = NULL;
    while(current_node != NULL) {
        next_node = current_node->next;
        current_node->next = head;
        head = current_node;
        current_node = next_node;
    }
    return head;
}
void output(LinkedList head) {
    Node *current_node = head;
    if(current_node == NULL) return;
    while( current_node->next != NULL) {
        printf("%c ", current_node->data);
        current_node = current_node->next;
    }
    printf("%c\n", current_node->data);
}
int main() {
    LinkedList linkedlist = NULL;
    int n;
    scanf("%d ", &n);
    char w;
    for(int i = 1; i <= n; i++) {
        scanf("%c ", &w);
        Node *node = (Node *)malloc(sizeof(Node));
        node->data = w;
        node->next = NULL;
        linkedlist = insert(linkedlist, node, i - 1);
    }
    linkedlist = reverse(linkedlist);
    output(linkedlist);
    return 0;
}
