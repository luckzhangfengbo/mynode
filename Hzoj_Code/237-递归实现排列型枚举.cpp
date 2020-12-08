/*************************************************************************
	> File Name: 237-递归实现排列型枚举.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年03月11日 星期三 23时12分45秒
 ************************************************************************/
/*
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
int q[110], n, vis[110];
void dfs(int x) {
    if(q[0] == n) {
        for(int i = 1; i <= q[0]; i++) {
            cout << q[i] << ' ';
        }
        cout << endl;
        return;
    }
    for(int i = 1; i <= n;i++) {
        if(!vis[i]) {
            vis[i] = 1;
            q[++q[0]] = i;
            dfs(i + 1);
            q[q[0]--] = 0;
            vis[i] = 0;
        }
    }
    return;
}
int main(){
    cin >> n;
    dfs(1);
    return 0;
}
*/
/*
#include<stdio.h>
int q[110], vis[110];
int n;
void dfs(int x) {
    if(q[0] == n) {
        for(int i = 1;i <= q[0]; i++) {
            printf("%d ", q[i]);
        }
        printf("\n");
        return;
    }
    for(int i = 1;i <= n; i++) {
        if(!vis[i]) {
            vis[i] = 1;
            q[++q[0]] = i;
            dfs(i + 1);
            q[q[0]--] = 0;
            vis[i] = 0;
        }
    }
    return;
}

int main() {
    scanf("%d", &n);
    dfs(1);
    return 0;
}
*/
/*
#include<stdio.h>
int q[110], vis[110];
int n;
void dfs(int x) {
    if(q[0] == n) {
        for(int i = 1;i <= q[0]; i++) {
			if(i!=1)printf(" ");
            printf("%d", q[i]);
        }
        printf("\n");
        return;
    }
    for(int i = 1;i <= n; i++) {
        if(!vis[i]) {
            vis[i] = 1;
            q[++q[0]] = i;
            dfs(i + 1);
            q[q[0]--] = 0;
            vis[i] = 0;
        }
    }
    return;
}

int main() {
    scanf("%d", &n);
    dfs(1);
    return 0;
}
*/

#include<iostream>
using namespace std;

int n, num[15], cnt, vis[15];

void func(int left) {
    if(left == 0) {
        for(int i = 0; i < cnt; i++) {
            if(i) cout << " ";
            cout << num[i];
        }
        cout << endl;
    }
    for(int i = 1; i <= n; i++) {
        if(vis[i] == 0) {
            vis[i] = 1;
            num[cnt] = i;
            cnt++;
            func(left - 1);
            cnt--;
            vis[i] = 0;
        }
    }
}


int main() {
    cin >> n;
    func(n);
    return 0;
}

