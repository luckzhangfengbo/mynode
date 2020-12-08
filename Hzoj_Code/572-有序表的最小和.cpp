/*************************************************************************
	> File Name: 572-有序表的最小和.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年05月27日 星期三 14时52分19秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

long long n, num1[400005], num2[400005], ans[400005];

int main() {
    priority_queue<int>que;
    scanf("%lld", &n);
    for(int i = 0; i < n; i++) {
        scanf("%lld", &num1[i]);
    }
    for(int i = 0; i < n; i++) {
        scanf("%lld", &num2[i]);
        que.push(num1[0] + num2[i]);
    }
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int sum = num1[i] + num2[j];
            if(sum < que.top()) {
                que.pop();
                que.push(sum);
            } else {
                break;
            }
        }
    }
    for(int i = 0; i < n; i ++) {
        ans[i] = que.top();
        que.pop();
    }
    for(int i = n - 1; i>= 0; i--) {
        printf("%lld\n", ans[i]);
    }
    return 0;
}
