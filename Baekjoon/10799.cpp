/*
* https://www.acmicpc.net/problem/10799
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<char> s;
    string str;
    int sum = 0;
    
    cin >> str;

    for (int i = 0; i < str.size(); ++i)
    {
        if (str[i] == '(')
            s.push(str[i]);
        else
        {
            s.pop();
            if (str[i - 1] == '(')
                sum += s.size();
            else
                sum += 1;
        }
    }
    cout << sum;
}
