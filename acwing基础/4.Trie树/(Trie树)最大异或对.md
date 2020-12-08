题目：

在给定的N个整数A1，A2……ANA1，A2……AN中选出两个进行xor（异或）运算，得到的结果最大是多少？

#### 输入格式

第一行输入一个整数N。

第二行输入N个整数A1A1～ANAN。

#### 输出格式

输出一个整数表示答案。

#### 数据范围

1≤N≤105 1≤N≤105,
0≤Ai<2310≤Ai<231

#### 输入样例：

```
3
1 2 3
```

#### 输出样例：

```
3
```



１．暴力

```　cpp
int res;
for(int i = 0; i < n; i++) 
    for(int j = 0; j < i; j++) {
        res = max(a[i] ^ a[j]);
    }
```

２．改进（ｔｒｉｅ树优化第二层）

![](/home/fangsong/文档/图片/trie.png)

查询的时候从根节点开始，有分支尽量与不同节点的分支走，没有直接走，　走到叶子尽头时候此时是最大的。

只要走３１位

１０００００　＊　３１　＝　３１０００００则优化很快，　n * log(n) 级别

一个节点代表一个集合，也就是二进制这一位是０或１的值

例如：

５　６　３　４　

101  110  011  100

<font color = red>主要模拟思路先查找后插入－></font>

![](/home/fangsong/文档/图片/trie2.png)



代码：(trie树改进)

```cpp
#include<iostream>
#include <algorithm>
using namespace std;
const int N = 100010, M = 31 * N;
int n;
int a[N];
int son[M][2], idx;

void insert(int x) {
    int p = 0;
    for(int  i = 30; i >= 0; i--) {
        int u = x >> i & 1;
        if(!son[p][u])son[p][u] = ++ idx;
        p = son[p][u];
    }
}

int query(int x) {
    int p = 0, res = 0;
    for(int i = 30; i >= 0; i --) {
        int u = x >> i & 1;
        if(son[p][!u]) {    // 如果另外一个方向存在，就走另外一个方向
            p = son[p][!u];
            res = res * 2 + !u;　// res * 2 + !u= res << 1 + !u 
        } else {　 // 如果另外一个方向不存在，就直接走
            p = son[p][u];　
            res = res * 2 + u;
        }
    }
    return res;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    int res = 0;
    for(int i = 0; i < n; i++) {
        insert(a[i]);
        int t = query(a[i]);
        res = max(res, a[i] ^ t);
    }
    cout << res; 
    return 0;
}

```

