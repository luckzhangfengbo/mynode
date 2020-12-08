/*************************************************************************
	> File Name: 223-线段树模板2.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年06月08日 星期一 21时27分41秒
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

#define MAX_N 10000
#define lc(ind) (tree[ind].lind)
#define rc(ind) (tree[ind].rind)
#define tag(ind) tree[ind].tag
#define sum(ind) tree[ind].sum
#define cnt(ind) tree[ind].cnt
struct node{
    long long sum;
    long long lind, rind;
    long long tag, cnt;
} tree[(MAX_N << 1) + 5];
long long root = 0, cnt = 1;
long long arr[MAX_N + 5];
long long getNode() {return cnt++;}

void DOWN(long long ind) {
    if(tag(ind)) {
        tag(lc(ind)) += tag(ind);
        tag(rc(ind)) += tag(ind);
        sum(lc(ind)) += tag(ind) * cnt(lc(ind));
        sum(rc(ind)) += tag(ind) * cnt(rc(ind));
        tag(ind) = 0;
    }
    return ;
}

void UP(long long ind) {
    tree[ind].sum = tree[lc(ind)].sum + tree[rc(ind)].sum;
}


void build(long long ind,  long long l, long long r) {
    tree[ind].cnt = (r - l + 1);
    if(l == r) {
        tree[ind].sum = arr[l];
        return;
    }
    long long mid = (l + r) >> 1;
    tree[ind].lind = getNode();
    tree[ind].rind = getNode();
    build(lc(ind), l, mid);
    build(rc(ind), mid + 1, r);
    UP(ind);
    return ;
}

void modify(long long ind,  long long x, long long y, long long d, long long l, long long r) {
    if(x <= l && r <= y) {
        tree[ind].tag += d;
        tree[ind].sum += d * tree[ind].cnt;
        return;
    }
    DOWN(ind);
    long long mid = (l + r) >> 1;
    if(x <= mid) modify(lc(ind), x, y, d, l , mid);
    if(y > mid) modify(rc(ind), x, y, d, mid + 1, r);
    UP(ind);
    return;
}

long long query( long long ind, long long x, long long y, long long l, long long r) {
    if(x <= l && r <= y) {
        return sum(ind);
    }
    DOWN(ind);
    long long mid = (l + r) >> 1, ans = 0;
    if(x <= mid) ans += query(lc(ind), x, y, l ,mid);
    if(y > mid) ans += query(rc(ind), x, y, mid + 1, r);
    return ans;
}

int main() {
    long long n, m;
    cin >> n >> m;
    for(long long i = 1; i <= n; i++) cin >> arr[i];
    build(root, 1, n);
    for(long long i = 0; i < m; i++) {
        long long a, b, c, d;
        cin >> a >> b >> c;
        if(a == 1) {
            cin >> d;
            modify(root, b, c, d, 1, n);
        } else {
            cout << query(root, b, c, 1 , n) << endl;
        }
    }
}
