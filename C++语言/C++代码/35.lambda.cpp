/*************************************************************************
	> File Name: 35.lambda.cpp
	> Author:fangsong
	> Mail: fangsong517@gmail.com
	> Created Time: 2020年08月17日 星期一 10时30分56秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<map>
#include<vector>
#include<set>
#include<functional>
using namespace std;
/*外部变量访问方式说明符

[] 不捕获任何变量
[&] 以引用方式捕获所有变量
[=] 用值的方式捕获所有变量（可能被编译器优化为const &)
[=, &foo] 以引用捕获foo, 但其余变量都靠值捕获
[&, foo] 以值捕获foo, 但其余变量都靠引用捕获
[bar] 以值方式捕获bar; 不捕获其它变量
[this] 捕获所在类的this指针
* 
* 捕获的最后一个赋值的
* */

int mul(int a, int b) {
    return a * b;
}

int add(int a, int b) {
    return a + b;
}
int main() {
    int n = 10000, m, x, y;
    auto a = [&](int a, int b) {return a + b + n;};
    n = 1000000;
    auto b = [&n](int a, int b){return a + b + n;};
    auto c = [](function<int(int, int)> a, function<int(int, int)> b) {
        return [=](int x) {
            return a(x, x) + b(x, x);
        };
    };
    cout << typeid(a).name() << endl;
    cout << typeid(b).name() << endl;
    cout << a(1, 2) << endl;
    cout << b(1, 2) << endl;
    auto d = c(a, b);
    auto e = c(add, mul);
    cout << d(12) << endl;
    cout << d(12) << endl;
    return 0;
}
