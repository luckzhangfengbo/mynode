/*************************************************************************
	> File Name: 520-等式.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年05月27日 星期三 18时14分27秒
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

long long a, num[15000005];


int main() {
    cin >> a;
    for(int i = 1; i <= 15000000; i++) {
        num[i] = num[i - 1] + i;
    }
    for(int i = a;1; i++) {
        int l = i + 1, r = 15000000;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(num[mid] - num[i] == num[i - 1]) {
                cout << i << " " << mid << endl;
                return 0;
            }
            if(num[mid] - num[i] > num[ i - 1 ]) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
    }
    return 0;
}
