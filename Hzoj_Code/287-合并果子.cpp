/*************************************************************************
	> File Name: 287-合并果子.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年05月27日 星期三 15时07分38秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<map>
#include<queue>
#include<vector>
using namespace std;


int main() {
    priority_queue<int, vector<int>, greater<int> > q;
   // priority_queue<int, vector<int>, greater<int> > q;
    int n, w;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> w;
        q.push(w);
    }
    int s1, s2;
    long long int sum = 0;
    for(int i = 1; i <= n - 1; i++) {
        s1 = q.top();
        q.pop();
        s2 = q.top();
        q.pop();
        q.push(s1 + s2);
        sum += s1 + s2;
    }
    cout << sum << endl;
    return 0;
}

