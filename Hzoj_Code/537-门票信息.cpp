/*************************************************************************
	> File Name: 537-门票信息.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年03月19日 星期四 23时17分47秒
 ************************************************************************/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<vector>
using namespace std;

int l, c, ans_cnt, fu, yuan, cnt;
char let[30], ans[30];

int dfs(int s, int left) {
    if(left == 0) {
        if(yuan >= 1 && fu >= 2) {
            for(int i = 0; i < ans_cnt; i++) {
                cout << ans[i];
            }
            cout << endl;
            cnt++;
            if(cnt == 25000) {
                return -1;
            }
        }
        return 0;
    }
    for(int i = s; i < c; i++) {
        ans[ans_cnt] = let[i];
        ans_cnt++;
        int f = 0;
        if(let[i] == 'a' ||let[i] == 'e'||let[i] == 'i'||let[i] == 'o' || let[i]=='u' ) {
            yuan++;
            f = 1;
        } else {
            fu++;
        }

        if(dfs(i + 1, left - 1) == -1) {
            return -1;
        }
        ans_cnt--;
        if(f == 1) {
            yuan--;
        } else {
            fu--;
        }
    }
    return 0;
}
int main() {
    cin >>l >> c;
    for(int i = 0; i < c; i++) {
        cin >> let[i];
    }
    sort(let, let + c);
    dfs(0, l);
    return 0;
}

