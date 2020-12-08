/*************************************************************************
	> File Name: 15.args_template.cpp
	> Author:fangsong
	> Mail: fangsong517@gmail.com
	> Created Time: 2020年08月03日 星期一 17时12分22秒
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
using namespace std;

template<typename T>
void print(const T &a) {
    cout << a << endl;
}

template<typename T, typename ...ARGS>
void print(const T &a, ARGS ...args) {
    cout << a << " ";
    print(args...);
    return ;
}

template<int n, typename T, typename ...ARGS> 
struct ARG {
    typedef typename ARG<n - 1, ARGS...> ::getT getT;
    typedef ARG<n - 1, ARGS...> N;
};

template<typename T, typename ...ARGS>
struct ARG<0, T, ARGS...>{
    typedef T getT;
};

template<typename T>
struct ARG<0, T> {
    typedef T getT;
    typedef T finalT;
};

template<typename T, typename ...ARGS> class Test;
template<typename T, typename ...ARGS>
class Test<T(ARGS...)>{
public:
    T operator()(typename ARG<0, ARGS...>::getT a, typename ARG<1, ARGS...>::N::finalT b) {
        return a + b;
    }
};

int main() {
    print(123, "hello world", 78, 1.05);
    Test<int(double, float)> e;
    cout << e(2.3, 4.5) << endl;
    return 0;
}
