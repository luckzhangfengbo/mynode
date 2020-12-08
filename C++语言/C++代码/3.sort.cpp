/*************************************************************************
	> File Name: 3.sort.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年07月21日 星期二 20时53分51秒
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

bool cmp(int a, int b) {
    return a > b;
}
struct CMP_FUNC{
    bool operator()(int a, int b){
        return a > b;
    }
};

int main() {
    int arr[1000], n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    nth_element(arr, arr + 1 ,arr + n);//排名第二的
    cout << arr[1] << endl << endl;
    sort(arr, arr + n, CMP_FUNC());
    sort(arr, arr + n, [](int a, int b) -> bool {return a > b;});
    for(int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }
    return 0;
}
