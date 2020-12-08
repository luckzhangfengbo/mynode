/*************************************************************************
	> File Name: 637-排序.cpp
	> Author:fangsong
	> Mail: fangsong517@gmail.com
	> Created Time: 2020年07月29日 星期三 18时16分45秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

struct edge {
    int to, next;
};

edge edg[10000];
int n, m, edg_cnt, ans_cnt, head[30], in_degree[30];
char ans[30];

void insert_edge(int a, int b, int x) {
    edg[x].to = b;
    edg[x].next = head[a];
    head[a] = x;
    edg_cnt = x + 1;
    in_degree[b]++;//入度
}

int check() {
    int temp_in[30];//定义临时入度
    ans_cnt = 0;//答案计数器清零
    queue<int> que;
    for (int i = 1; i <= n; i++) {
        temp_in[i] = in_degree[i];
        if (temp_in[i] == 0) {
            //说明是起点
            que.push(i);
        }
    }
    int f1 = que.size(), f2 = 0;//起点的数量如果不为1说明答案不确定
    while (!que.empty()) {
        int t = que.front();
        int f3 = 0;
        que.pop();
        ans[++ans_cnt] = t + 'A' - 1;
        for (int i = head[t]; i != -1; i = edg[i].next) {
            int e = edg[i].to;
            temp_in[e]--;//零食入度减一
            if (temp_in[e] == 0) {
                if (f3 == 1) {
                    f3 == 2;//说明有两个以上的点入度为0 说明答案不确定
                } else if (f3 == 0){
                    f3 = 1;
                }
                que.push(e);
            }
        }
        if (f3 == 2) {
            f2 = 2;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (temp_in[i] != 0) {
            //成环了
            return 1;
        }
    }
    if (f1 != 1 || f2 == 2) {
        //没求出答案
        return 0;
    }
    return 2;
}

int main() {
    memset(head, -1, sizeof(head));
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        char a, b;
        cin >> a >> b >> b;
        insert_edge(a - 'A' + 1, b - 'A' + 1, i);
        int t = check();//返回0说明普通 返回1 成环 2正确答案
        if (t == 1) {
            cout << "Inconsistency found after " << i + 1 << " relations." << endl;
            return 0;
        } else if (t == 2){
            cout << "Sorted sequence determined after " << i + 1 << " relations: ";
            for (int i = 1; i <= ans_cnt; i++) {
                cout << ans[i];
            }
            cout << "." << endl;
            return 0;
        }
    }
    cout << "Sorted sequence cannot be determined." <<  endl;
    return 0;
}
