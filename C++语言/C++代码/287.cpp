/*************************************************************************
	> File Name: 287.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年07月23日 星期四 18时53分14秒
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

struct my_int{
    int num;
    bool operator< (const my_int & b) const {
        return this->num > b.num;
    }
};

int main() {
    priority_queue<my_int> q;
   // priority_queue<int, vector<int>, greater<int> > q;
    int n, w;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> w;
        q.push((my_int){w});
    }
    int s1, s2;
    int sum = 0;
    for(int i = 1; i <= n - 1; i++) {
        s1 =(int)q.top().num;
        q.pop();
        s2 =(int)q.top().num;
        q.pop();
        q.push((my_int){s1 + s2});
        sum += s1 + s2;
    }
    cout << sum << endl;
    return 0;
}

