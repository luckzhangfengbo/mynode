/*************************************************************************
	> File Name: buttle_sort.cpp
	> Author: 
	> Mail: 
	> Created Time: 六  9/17 19:30:03 2022
 ************************************************************************/

#include<iostream>
using namespace std;


#define max_n 1000

int a[max_n];

void buttle_sort(int *a, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    return ;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    buttle_sort(a, n);
    for (int i = 0; i < n; i++) {
        cout << " " <<a[i] << endl;
    }

    return 0;
}
