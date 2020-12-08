/*************************************************************************
	> File Name: 33.turing.cpp
	> Author:fangsong
	> Mail: fangsong517@gmail.com
	> Created Time: 2020年08月13日 星期四 14时25分59秒
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

//IsEven
template<int n>
struct IsEven {
    static constexpr int r = !(n % 2);
};

//Add
template<int a, int b>
struct Add{
    static constexpr int r = (a + b);
};
//Sum
template<int n>
struct Sum{
    static constexpr int r = n + Sum<n - 1>::r;
};
template<>
struct Sum<0> {
    static constexpr int r = 0;  
};
//Factorial
template<int n>
struct Factorial{
    static constexpr int r = n * Factorial<n - 1>::r;
};
template<>
struct Factorial<1> {
    static constexpr int r = 1;
};

//is_prime

template<int n, int i>
struct getNextN{
    static constexpr int r = (i * i > n ? 0 : n);
};

template<int n, int i>
struct getNextI {
    static constexpr int r = (n % i == 0 ? 0 : i + 1);
};

template<int n, int i>
struct IsTest{
    static constexpr int r = IsTest<getNextN<n, i>::r, getNextI<n, i>::r>::r;
};

template<int i>
struct IsTest<2, i> {
    static constexpr int r = 1;
};

template<int i>
struct IsTest<0, i> {
//走到最后都没找到整除的那就是素数
    static constexpr int r = 1;
};

template<int n>
struct IsTest<n, 0> {
//在到n之间有能整除的i他就不是素数
    static constexpr int r = 0;
};


template<int n>
struct IsPrime{
    static constexpr int r = IsTest<n, 2>::r;
};

//count_prime

template<int n>
struct SumPrime {
    static constexpr int r = n * IsPrime<n>::r + SumPrime<n - 1>::r;
};
template<>
struct SumPrime<2> {
    static constexpr int r = 2;
};


template<int x, int i>
struct __output {
    static void run() {
        if(IsPrime<i>::r) {
            cout << i << endl;
        }
        __output<x, i + 1>::run();
    }
};

template<int x>
struct __output<x, x> {
    static void run() {
        return ;
    }
};

template<int x> 
struct print_prime{
    static void output() {
        __output<x + 1, 2>::run();
        return;
    }
};

int main() {
    cout << IsEven<123>::r << endl;
    cout << IsEven<124>::r << endl;
    cout << Add<123, 456>::r << endl;
    cout << Sum<10>::r << endl;
    cout << Sum<100>::r << endl;
    cout << Factorial<5>::r << endl;
    cout << Factorial<10>::r << endl;
    cout << IsPrime<9973>::r << endl;
    cout << SumPrime<5>::r << endl;
    print_prime<100>::output();
    return 0;
}
