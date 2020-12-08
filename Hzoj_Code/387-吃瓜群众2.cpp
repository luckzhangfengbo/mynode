/*************************************************************************
	> File Name: 387-吃瓜群众2.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年04月08日 星期三 20时04分13秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

struct node {
    int num, val;
};
node wm[100005];

bool cmp(node a, node b) {
    return a.val < b.val;
}

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        scanf("%d",&wm[i].val);
        wm[i].num = i + 1;
    }
    sort(wm, wm + n, cmp);
    for(int i = 0; i < m; i++) {
        int t;
        cin >> t;
        if(t > wm[n - 1].val) {
            printf("0\n");
            continue;
        }
        int l = 0, r = n - 1;
        while(l != r) {
            int mid = (l + r) >> 1;
            if(wm[mid].val >= t) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        printf("%d\n", wm[l].num);
    }
    return 0;
}

