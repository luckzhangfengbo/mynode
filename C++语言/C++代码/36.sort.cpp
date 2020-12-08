/*************************************************************************
	> File Name: 36.sort.cpp
	> Author:fangsong
	> Mail: fangsong517@gmail.com
	> Created Time: 2020年08月17日 星期一 14时31分59秒
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

bool cmp(int a, int b) {
    return a > b;
}


struct CMP{
    bool operator()(int a, int b) {
        return a > b;
    }
};
namespace haizei{
template<typename T>
struct less{
    bool operator()(const T &a, const T & b) {
        return a < b;
    }
};

template<typename T>
struct greater{
    bool operator()(const T &a, const T &b) {
        return a > b;
    }
};
}

int main() {
    srand(time(0));
    int arr[10];
    for(int i = 0; i < 10; i++) arr[i] = rand() % 100;
    sort(arr, arr + 10, haizei::less<int>());
    sort(arr, arr + 10, haizei::greater<int>());
    for(int i = 0; i < 10; i++) cout << arr[i] << " ";
    cout << endl;
    return 0;
}
