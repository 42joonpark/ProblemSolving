/*
* https://www.acmicpc.net/problem/9012
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    for (cin >> t; t > 0; --t)
    {
        string str;
        stack<char> s;
        bool succ = true;

        cin >> str;
        for (int i = 0; i < str.size(); ++i)
        {
            if (str[i] == '(')
                s.push(str[i]);
            else if (str[i] == ')')
                if (s.empty() || s.top() == ')')
                    succ = false;
                else
                    s.pop(); 
        }
        if (!succ || !s.empty()) cout << "NO\n";
        else cout << "YES\n";
    }
}
