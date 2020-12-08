## Trie 树

高效的存储和查找字符串的集合的数据结构

例如如果要是存储：

```cpp
abcdef
abdef
aced
bcdf
bcdf
bcff
cdaa
bcdc
```



<img src="./图片/trie树.png" style="zoom:50%;" />

先做个标记 `f , f, d, f, c, f, a,`

插入：

如果要是插入一个`abc`, 就是以'c'结尾的标记

<img src="/home/fangsong/文档/图片/trie树１.png" style="zoom:50%;" />

查找：（快速查找）

例如我们想要查询一个存在的字符串`aced`，从根节点开始查询，ａｃｅｄ，　ｄ正好未标记的一个点，所以查找到，存在。若查找不存在的`acbf` , acb ,f不存在，未找到。



```cpp
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
const int N = 1000010;
char str[N];
int son[N][26], cnt[N], idx;　 // 下表是０的点也是根节点，空节点,  son[N][26]：因为一个节点最多有２６个子节点，ｃｎｔ是以当前这个点结尾的单词有多少个，　ｉｄｘ当前用到的是那个下表，　如果一个带你没有子节点，　也让他指向０
void insert(char str[]) {　// 插入操作，　插入一个字符串
    int p = 0;
    for(int i = 0;str[i]; i++) {　 // p = 0, 从根节点开始，　遍历这个个字符串
        int u = str[i] - 'a';　　// 将小写字母a ~z 映射成0 ~ 25;
        if(!son[p][u]) son[p][u] = ++idx;  // 如果不存在就创建出来
        p = son[p][u];
    } 
    cnt[p]++;　// 就是说以这个结尾的单词多了一个
}
int query(char str[]) {　// 查询操作
    int p = 0;　
    for(int i = 0; str[i]; i++) {
        int u = str[i] - 'a';
        if(!son[p][u]) return 0; // 如不存在的话结束
        p = son[p][u];　// 继续走
    }
    return cnt[p];　// 返回以ｐ结尾的个数
}
int main() {
    int n;
    scanf("%d", &n);
    while(n --) {
        char op[2];
        scanf("%s%s", op, str);
        if(op[0] == 'I')insert(str);
        else printf("%d\n", query(str));
    }
    return 0;
}
```

