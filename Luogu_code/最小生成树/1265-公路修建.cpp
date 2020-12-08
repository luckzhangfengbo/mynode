/*************************************************************************
	> File Name: 1265-公路修建.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年07月15日 星期三 18时11分57秒
 ************************************************************************/
#include<iostream>
#include <cmath>
#include <cstdio>
#include <queue>
#include <cstring>
#include <cstdio>

using namespace std;

struct node {
  int now;
  double val;
  bool operator< (const node& b) const {
    return this->val > b.val;
  }
};

int n, xy[5005][2], vis[5005];
double dis[5005];

double distance(int a, int b) {
  long long x = xy[a][0] - xy[b][0], y = xy[a][1] - xy[b][1];
  return sqrt(x * x + y * y);
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    dis[i] = 9999999999;
  }
  for (int i = 1; i <= n; i++) {
    cin >> xy[i][0] >> xy[i][1];
  }
  priority_queue<node> que;
  que.push((node){ 1, 0 });
  dis[1] = 0;
  double ans = 0;
  int already = 0;
  while (!que.empty()) {
    node temp = que.top();
    que.pop();
    if (vis[temp.now] == 1) {
      continue;
    }
    vis[temp.now] = 1;
    ans += temp.val;
    already++;
    if (already == n) {
      break;
    }
    for (int i = 1; i <= n; i++) {
      double t = distance(temp.now, i);
      if (i == temp.now) {
        continue;
      }
      if (t < dis[i]) {
        dis[i] = t;
        que.push((node){ i, t });
      }
    }
  }
  printf("%.2f\n", ans);
  return 0;
}
