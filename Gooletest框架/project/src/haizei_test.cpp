#include <stdio.h>
#include <haizei_test.h>
#include <string.h>
#include <stdlib.h>
struct Func_Data head, *tail = &head;

int RUN_ALL_TESTS() {
    struct Func_Data *p = head.next;
    for(;p!=NULL; p=p->next) {
        printf("[=== RUN ===] %s\n", p->func_name);
        p->func();
    }
    return 0;
}
void add_function(Func_T func, const char *str) {
    struct Func_Data *p = (struct Func_Data *)malloc(sizeof(struct Func_Data));
    p->func = func;
    p->func_name = strdup(str);
    p->next = NULL;
    tail->next = p;
    tail = p;
    return ;
}
