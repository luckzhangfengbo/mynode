/*************************************************************************
	> File Name: 534-体积.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年03月19日 星期四 23时16分28秒
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
int n;
int a[100];
int num[150], cnt, sum;
int w[150000], k = 0, t = 0;
void p() {
    int sum = 0;
    for(int i = 0; i < cnt; i++) {
        sum += num[i];
    }
    if(!w[sum])t++;
    w[sum] = 1;
}
void dfs(int s) {
    for(int i = s; i <= n; i++) {
        num[cnt] = a[i];
        cnt++;
        p();
        dfs(i + 1);
        cnt--;
    }
}


int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dfs(1);
    cout << t << endl;
    return 0;
}
*/

#include<iostream>
using namespace std;

int n, num[25], check[1005] = {1}, ans;

void dfs(int s, int sum) {
    if(check[sum] == 0) {
        ans++;
        check[sum] = 1;
    }
    for(int i = s; i <= n; i++) {
        sum += num[i];
        dfs(i + 1, sum);
        sum -= num[i];
    }
    
}
int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> num[i];
    }
    dfs(0, 0);
    cout << ans << endl;

    return 0;
}

