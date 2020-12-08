/*************************************************************************
	> File Name: 241-最近点对.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年05月06日 星期三 18时56分36秒
 ************************************************************************/

/*一个集合中最近点对*/
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

struct node {
    double x, y;
};

bool cmp(node a, node b) {
    if(a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

int n;
node p[100005];

double dis(int p1, int p2) {
    return sqrt((p[p1].x - p[p2].x) * (p[p1].x - p[p2].x) +  (p[p1].y - p[p2].y) * (p[p1].y - p[p2].y));
}

double func(int l, int r) {
    if(l == r) {
        return 222222222222;
    }
    if(l + 1 == r) {
        return dis(l, r);
    }
    int mid = (l + r) >> 1; //分为两部分
    double d = min(func(l, mid), func(mid + 1, r));//左集合，右集合找一个最小的
    for(int i = mid; i >= 0 && p[mid].x - p[i].x < d; i--) {//求两个集合之间最小的一个
        for(int j = mid + 1; j < r && p[j].x - p[mid].x < d; j++) {
            d = min(d, dis(i, j));//与两个集合中最小的那个比较
        }
    }
    return d;
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%lf%lf", &p[i].x, &p[i].y);
    }
    sort(p, p + n,cmp);
    double ans = func(0, n - 1);
    printf("%lf\n", ans);
    return 0;
}

*/


/*两个集合中最近的点对*/
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

struct node {
    double x, y, z;
};

bool cmp(node a, node b) {
    if(a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

int n;
node p[200005];

double dis(int p1, int p2) {
    return sqrt((p[p1].x - p[p2].x) * (p[p1].x - p[p2].x) +  (p[p1].y - p[p2].y) * (p[p1].y - p[p2].y));
}

double func(int l, int r) {
    if(l == r) {
        return 222222222222;
    }
    if(l + 1 == r) {
        if(p[l].z != p[r].z)return dis(l, r);
        return 222222222222;
    }
    int mid = (l + r) >> 1; //分为两部分
    double d = min(func(l, mid), func(mid + 1, r));//左集合，右集合找一个最小的
    for(int i = mid; i >= l && p[mid].x - p[i].x < d; i--) {//求两个集合之间最小的一个
        for(int j = mid + 1; j <= r && p[j].x - p[mid].x < d; j++) {
            if(p[i].z != p[j].z) d = min(d, dis(i, j));//与两个集合中最小的那个比较
        }
    }
    return d;
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%lf%lf", &p[i].x, &p[i].y);
        p[i].z = 1;
    }
    for(int i = 2 * n -1; i >= n; i--) {
        scanf("%lf%lf", &p[i].x, &p[i].y);
        p[i].z = 2;
    }
    sort(p, p + 2 * n,cmp);
    double ans = func(0, 2 * n - 1);
    printf("%.3lf\n", ans);
    return 0;
}
*/

#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;

struct node {
    double x, y, z;
};

bool cmp(node a, node b) {
    if(a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

int n, px[2000005], px_ind;
node p[200005];

double dis(int p1, int p2) {
    return sqrt((p[p1].x - p[p2].x) * (p[p1].x - p[p2].x) +  (p[p1].y - p[p2].y) * (p[p1].y - p[p2].y));
}

bool cmp2(int a, int b) {
    return p[px[a]].y < p[px[b]].y;
}

double func(int l, int r) {
    if(l == r) {
        return 222222222222;
    }
    if(l + 1 == r) {
        if(p[l].z != p[r].z)return dis(l, r);
        return 222222222222;
    }
    int mid = (l + r) >> 1; //分为两部分
    double d = min(func(l, mid), func(mid + 1, r));//左集合，右集合找一个最小的
    int raw = px_ind;
    for(int i = mid; i >= l && p[mid].x - p[i].x < d; i--) {//求两个集合之间最小的一个
         px[px_ind++] = i;
    }
    for(int j = mid + 1; j <= r && p[j].x - p[mid].x < d; j++) {
          px[px_ind++] = j;
    }
    sort(px + raw, px + px_ind , cmp2);
    for(int i = raw; i < px_ind; i++) {
        for(int j = i + 1; j < px_ind && p[px[j]].y - p[px[i]].y < d; j++) {
            if(p[px[i]].z != p[px[j]].z) d=min(d, dis(px[i], px[j]));
        }
    }
    return d;
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%lf%lf", &p[i].x, &p[i].y);
        p[i].z = 1;
    }
    for(int i = 2 * n -1; i >= n; i--) {
        scanf("%lf%lf", &p[i].x, &p[i].y);
        p[i].z = 2;
    }
    sort(p, p + 2 * n,cmp);
    double ans = func(0, 2 * n - 1);
    printf("%.3lf\n", ans);
    return 0;
}



