/*************************************************************************
	> File Name: 14.template.cpp
	> Author:fangsong
	> Mail: fangsong517@gmail.com
	> Created Time: 2020年08月03日 星期一 15时48分21秒
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
T add(T a, T b) {
    cout << "add function : " << sizeof(T) << endl;
    static int i = 0;
    cout <<"i : "<< (++i) << endl;
    return a + b;
}

template<>
int add(int a, int b) {
    cout << "specific template add function" << endl;
    return a + b;
}

template<typename T>
T add(T *a, T *b) {
    cout << "T * add function" << endl;
    return *a + *b;
}

template<typename T>
class Array {
public:
    Array(int n) : n(n) {
        this->arr = new T[n];
    }
    T &operator[](int ind) {
        if(ind < 0 || ind >= n) return this->__end;
        return this->arr[ind];    
    }
    template<typename U>
    friend ostream &operator<< (ostream &, const Array<U> &);
private:
    T *arr;
    T __end;
    int n;
};

template<typename T>
ostream &operator<<(ostream &out, const Array<T> &a) {
    out << "Class Array : ";
    for(int i = 0; i < a.n; i++) {
        out << a.arr[i] << " " << endl;
    }
    return out;
}



template<>
class Array<double> {
public:
    Array(int n) : n(n) {
        cout << "double array template" << endl;
        this->arr = new double[n];
    }
    double &operator[](int ind) {
        if(ind < 0 || ind >= n) return this->__end;
        return this->arr[ind];    
    }
    template<typename T>
    friend ostream &operator<<(ostream &, const Array<T> &);
private:
    double *arr;
    double __end;
    int n;
};

int main() {
    int a_num = 123, b_num = 456;
    cout << add(2, 3) << endl;
    cout << add(2.3, 4.5) << endl;
    cout << add<double>(2.3, 3) << endl;
    cout << add(&a_num, &b_num) << endl;
    Array<int>a(10);
    Array<double> b(10);
    a[0] = 123;
    a[-123] = 456;
    for(int i = 0; i < 10; i++) {
        b[i] = (rand() % 100)/100.0;
    }
    cout << a << endl;
    cout << b << endl;
    return 0;
}
