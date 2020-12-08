#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node, *LinkedList;

Node insert(LinkedList head, Node *node, int index) {
    Node *p, ret;
    p = &ret;
    ret.data = 0;
    ret.next = head;
    while(p->next && index) {
        p = p -> next;
        --index;
    }
    if(index == 0) {
        node->next = p->next;
        p->next = node;
        ret.data = 1;
    }
    return ret;
}

void output(LinkedList head) {
    if(head == NULL) {
        return;
    }
    Node *current_node = head;
    printf("%d", current_node->data);
    current_node = current_node->next;
    while(current_node != NULL) {
        printf(" %d", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

void clear(LinkedList head) {
    Node *current_node = head;
    while(current_node != NULL) {
        Node *delete_node = current_node;
        current_node = current_node->next;
        free(delete_node);
    }
}

int main() {
    LinkedList linkedlist = NULL;
    int n;
    scanf("%d", &n);
    int p, q;
    for(int i = 0; i < n ;i++) {
        scanf("%d %d", &p, &q);
        Node ret;
        Node *node = (Node *)malloc(sizeof(Node));
        node->next = NULL;
        node->data = q;
        ret = insert(linkedlist, node, p);
        linkedlist = ret.next;
        if(ret.data) {
            printf("success\n");
        } else {
            printf("failed\n");
        }
    }
    output(linkedlist);
    clear(linkedlist);
    return 0;
}
