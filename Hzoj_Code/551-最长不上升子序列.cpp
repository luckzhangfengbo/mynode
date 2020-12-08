/*************************************************************************
	> File Name: 551-最长不上升子序列.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年04月24日 星期五 16时32分00秒
 ************************************************************************/
/*
#include<bits/stdc++.h>
#define MAX 25
using namespace std;

int  main()
{
    int t,m;
    int missile[MAX];
    int d[MAX];
        cin>>m;
        for(int i = 1 ; i<=m ; i++)
            cin>>missile[i];

        memset(d,0,sizeof(d));
        for(int i = m - 1; i > 0; i--)
            for(int j = 0 ; j<=m ; j++)
                if(i<j&&missile[i]>missile[j])
                    d[i] = max(d[i],d[j]+1);

        int temp = d[1];
        for(int i = 1 ; i<=m ; i++)
            if(d[i]>temp)
                temp = d[i];
        cout<<temp+1<<endl;
    return 0;
}
*/

#include<iostream>
using namespace std;
#define MAX_N 2005
int a[MAX_N], d[MAX_N];
int main() {
    int n;
    cin >>n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = n - 1; i > 0; i--) {
        for(int j = i + 1; j <= n; j++) {
            if(a[i] > a[j]) {
                d[i] = max(d[i], d[j] + 1);
            }
        }
    }
    int temp = d[1];
    for(int i = 1; i <= n; i++) {
        if(d[i] > temp)temp = d[i];
    }
    cout << temp + 1 << endl;
    return 0;
}
