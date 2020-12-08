#include<iostream>
#include<map>
using namespace std;
int main() {
    map<string, int>m;
    int n;
    cin >> n;
    string s;
    for(int i = 1; i <= n; i++) {
        cin >> s;
        string w;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] >='A' && s[i] <= 'Z') {
                w += s[i] + 32;
            } else {
                w += s[i];
            }
        }
        if(m[w] == 0) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
        m[w]++;
    }
    return 0;
}
