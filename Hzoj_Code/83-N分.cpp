/*************************************************************************
	> File Name: 83-N分.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年03月11日 星期三 23时14分14秒
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
long w, m, n;
void dfs(long sum,int t,int k) {
    if(sum > n)return;
    if(k > m)return;
    if(k == m&&sum == n){w ++;return;}
    for(int i = t; i <= n - sum; i++) {
        dfs(sum + i,i, k + 1);
    }
    return;
}

int main() {
    scanf("%ld%ld", &n, &m);
    dfs(0, 1, 0);
    printf("%ld\n", w);
    return 0;
}
*/

#include<iostream>
using namespace std;
int w[150], cnt;
int m;
int dfs(int s, int left_num, int left_cnt) {
    if(left_cnt == 0) {
        if(left_num == 0) {
            for(int i = 0; i < m; i++) {
                if(i)cout << "+";
                cout << w[i];
            }
            cout << endl;
            return 1;
        }
        return 0;
    }
    int ans = 0;
    for(int i = s; i <=left_num; i++) {
        w[cnt] = i;
        cnt ++;
        ans += dfs(i, left_num - i, left_cnt - 1);
        cnt--;
    }
    return ans;
}

int main() {
    int n;
    cin >> n >> m;
    cout << dfs(1, n, m) << endl;
    return 0;
}

