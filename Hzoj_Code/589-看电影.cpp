/*************************************************************************
	> File Name: 589-看电影.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年05月06日 星期三 18时35分48秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
/*int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}*/
int main() {
    int n, k, id;
    cin >> n >> k >> id;
    int w =__gcd(n, k);
    cout << k / w << "/" << n / w << endl;
    return 0;
}
