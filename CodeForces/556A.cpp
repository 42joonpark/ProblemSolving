/*
* https://codeforces.com/problemset/problem/556/A
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    stack<char> s;
    string str;
    int n;
    cin >> n >> str;
    
    for (int i = 0; i < str.size(); ++i) {
        if (!s.empty() && str[i] != s.top())
            s.pop();
        else
            s.push(str[i]);
    }
    cout << s.size();
}
