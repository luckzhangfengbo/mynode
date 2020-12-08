#include<iostream>
#include<string>
using namespace std;
const int N = 100010;
//head 存储链表头，e[]存储节点的值，ne[]存储节点的next指针，idx表示当前用到了哪个节点
int head, e[N], ne[N], idx;

void init() {//初始化
    head = -1;
    idx = 0;
}

void add_head(int x) {//向链表头部插入一个数
    e[idx] = x;
    ne[idx] = head;
    head = idx;
    idx ++;
}
void add(int k, int x) {//在第k个输入的数后插入一个x
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx;
    idx++;
}

void remove(int k) {//删除第k个输入的数
    ne[k] = ne[ne[k]];
}

int main() {
    int n;
    cin >> n;
    init();
    while(n --) {
        string op;
        int k, x;
        cin >> op;
        if(op[0] == 'D') {
            cin >> k;
            if(!k)head = ne[head];
            remove(k - 1);
        } else if(op[0] == 'H') {
            cin >> x;
            add_head(x);
        } else if(op[0] == 'I') {
            int k, x;
            cin >> k >> x;
            add(k - 1, x);
        }
    }
    for(int i = head; i != -1; i = ne[i]) cout << e[i] << ' ';
    return 0;
}