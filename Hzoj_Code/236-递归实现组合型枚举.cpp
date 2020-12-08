/*************************************************************************
	> File Name: 236-递归实现组合型枚举.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年03月11日 星期三 23时12分13秒
 ************************************************************************/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
int n, m;
int ans[15];
int cnt;
void dfs(int s) {
    if(cnt == m) {
        for(int i = 0; i < cnt; i++) {
            if(i)cout << " ";
            cout << ans[i];
        }
        cout << endl;
        return;
    }
    for(int i = s; i <= n; i++) {
        ans[cnt]= i;
        cnt++;
        dfs(i + 1);
        cnt--;
    }
}
int main() {
    cin >> n >> m;
    dfs(1);
    return 0;
}
/*


#include<iostream>
using namespace std;

int n, m, num[15], cnt;

void func(int s, int left) {
    if(left == 0) {
        for(int i = 0; i < cnt; i++) {
            if(i) cout << " ";
            cout << num[i];
        }
        cout << endl;
        return;
    }
    for(int i = s; i <= n - left + 1; i++) {
        num[cnt] = i;
        cnt++;
        func(i + 1, left - 1);
        cnt--;
    }
}

int main() {
    cin >> n >> m;
    func(1, m);
    return 0;
}
*/

