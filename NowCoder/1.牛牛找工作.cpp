/*************************************************************************
	> File Name: 1.牛牛找工作.cpp
	> Author:fangsong
	> Mail: fangsong517@gmail.com
	> Created Time: 2020年08月19日 星期三 16时06分06秒
 ************************************************************************/
//https://www.nowcoder.com/questionTerminal/46e837a4ea9144f5ad2021658cb54c4d
#include<iostream>
#include<algorithm>
using namespace std;
struct node{
    int diff, money;
};

bool cmp(node a, node b) {
    return a.diff < b.diff;
}
node work[100005];
int n, m, ans[100005];

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> work[i].diff >> work[i].money;
    }
    sort(work, work + n, cmp);
    ans[0] = work[0].money;
    for(int i = 1; i < n; i++) {
        ans[i] = max(ans[i - 1], work[i].money);
    }
    for(int i = 0; i < m; i++) {
        int t, l = 0, r = n - 1;
        cin >> t;
        if(t < work[0].diff) {
            cout << 0 << endl;
            continue;
        }
        while(l != r) {
            int mid = (l + r + 1) /2;
            if(work[mid].diff <= t) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        cout << ans[l] << endl;
    }

    return 0;
}
