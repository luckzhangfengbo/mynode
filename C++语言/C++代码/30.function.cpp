/*************************************************************************
	> File Name: 30.function.cpp
	> Author:fangsong
	> Mail: fangsong517@gmail.com
	> Created Time: 2020年08月08日 星期六 15时25分35秒
 ************************************************************************/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <functional>
using namespace std;

namespace haizei {
template<typename RT, typename ...PARAMS>
class base{
public :
    virtual RT operator()(PARAMS...) = 0;
    virtual base *getCopy() = 0;
    virtual ~base() {}
};

template<typename RT, typename ...PARAMS>
class normal_func :public base<RT, PARAMS...>{//继承base
public:
    typedef RT (*(func_type))(PARAMS...);
    normal_func(func_type func) : ptr(func){}
    virtual RT operator()(PARAMS...args) override{
        return this->ptr(args...);
    }
    virtual base<RT, PARAMS...> *getCopy() override{
        return new normal_func<RT, PARAMS...>(ptr);
    }
private:
    func_type ptr;
};

template<typename C,typename RT, typename ...PARAMS>
class functor :public base<RT, PARAMS...>{
    //继承base
public:
    typedef RT (*(func_type))(PARAMS...);
    functor(C &func) : ptr(func){}
    virtual RT operator()(PARAMS...args) override{
        return this->ptr(args...);
    }
    virtual base<RT, PARAMS...> *getCopy() override{
        return new functor<C, RT, PARAMS...>(ptr);
    }
private:
    C &ptr;
};

template<typename RT, typename ...PARAMS> class function;
template<typename RT, typename ...PARAMS>
class function<RT(PARAMS...)> {
public :
    function(RT (*func)(PARAMS...))//传入普通函数的构造函数
    :ptr(new normal_func<RT, PARAMS...>(func)){//普通函数构造
        cout << "normal function constructor" << endl;
    }
    template<typename T>//传入函数对象的构造函数
    function(T a)
    : ptr(new functor<typename remove_reference<T>::type, RT, PARAMS...>(a)){//对象构造函数
        cout << "function object constructor" << endl;
    }
    function(const function &f) {
        this->ptr = f.ptr->getCopy();
    }
    function(function &&f) {
        this->ptr = f.ptr;
        f.ptr = nullptr;
    }
    RT operator()(PARAMS... args) {
        return this->ptr->operator()(args...);
    }
    ~function() {
        if(ptr != nullptr)delete ptr;
    }

private :
    base<RT, PARAMS...> *ptr;
//步骤2,把函数或函数对象打包成一个新的函数对象(即为base类，为了记录数据),然后把这个新的函数对象地址存下来。
};

} // end of haizei

void f(function<int(int, int)> g) {
//返回值为int,传入两个参数int,g为对象名；步骤１．g对象(的赋值)可以接受普通函数和函数对象，然后调用构造函数。
    cout << g(3, 4) << endl;
    return ;
}

int add(int a, int b) {
    return a + b;
}


struct MaxClass {
    int operator()(int a, int b) {
        return a > b ? a : b;
    }
};
template<typename RT, typename ...ARGS>class FunctionCnt;
template<typename RT, typename ...ARGS>
class FunctionCnt<RT(ARGS...)>{
public:
    FunctionCnt(haizei::function<RT(ARGS...)> g) : g(g), __cnt(0){}
    RT operator()(ARGS ...args) {
        __cnt ++;
        return g(args...);
    }
    int cnt(){return __cnt;}
private:
    haizei::function<RT(ARGS...)>g;
    int __cnt;
};

/*
class FunctionCnt{
    public:
    FunctionCnt(function<int(int, int)> g) : g(g), __cnt(0){}
    int operator()(int a, int b) {
        __cnt ++;
        return g(a, b);
    }
    int cnt(){return __cnt;}
    private:
    function<int(int, int)>g;
    int __cnt;
};
*/
//实现任意参数加法
template<typename T, typename ...ARGS>class ADD;
template<typename T, typename ...ARGS>
struct ADD<T(ARGS...)>{
public:
    T operator()(ARGS... args){
        return add<T>(args...);
    }
private:
    template<typename T1, typename U, typename ...US>
    T1 add(U a, US ...args) {
        return a + add<T1>(args...);
    }
    template<typename T1, typename U>
    T1 add(U a) {
        return a;
    }
};


int main() {
    int n;
    decltype(n) m;
    cout << sizeof(m) << endl;
    MaxClass max;
    f(add);
    f(max);
    haizei::function<int(int, int)> g1(add);
    haizei::function<int(int, int)> g2(max);
    cout << g1(3, 4) << endl;
    cout << g2(3, 4) << endl;
    
    FunctionCnt<int(int, int)> add_cnt(add);
    //FunctionCnt add_cnt(add);
    cout << add_cnt(3, 4) << endl;
    cout << add_cnt(4, 5) << endl;
    cout << add_cnt.cnt() << endl;
    ADD<double(int, double)>f;
    FunctionCnt<double(int, double)> ADD_cnt(f);
    cout << ADD_cnt(11, 2.2) << endl;
    return 0;
}
