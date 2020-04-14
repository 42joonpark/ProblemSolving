/*
* https://codeforces.com/problemset/problem/58/A
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    const string hello = "hello";
    string str;
    int i = 0, k = 0;
    
    cin >> str;
    while (i < str.size() && k < hello.size()) {
        if (str[i] == hello[k]) ++k;
        ++i;
    }
    
    if (k >= hello.size()) cout << "YES\n";
    else cout << "NO\n";
}
