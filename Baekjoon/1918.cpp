/*
* https://www.acmicpc.net/problem/1918
*/
#include <bits/stdc++.h>
using namespace std;

string str, answer = "";
stack<char> s;
int priority(char c)
{
    if (c == '(' || c == ')') return 0;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}
int main()
{

    cin >> str;
    for (int i = 0; i < str.size(); ++i)
    {
        char c = str[i];
        if (isalpha(c))
            answer += c;
        else if (c == '(')
            s.push(c);
        else if (c == '*' || c == '/' || c == '+' || c == '-')
        {
            while (!s.empty() && priority(c) <= priority(s.top()))
            {
                answer += s.top();
                s.pop();
            }
            s.push(c);
        }
        else if (c == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                answer += s.top();
                s.pop();
            }
            s.pop();
        }
    }

    while (!s.empty())
    {
        answer += s.top();
        s.pop();
    }
    cout << answer;
}
