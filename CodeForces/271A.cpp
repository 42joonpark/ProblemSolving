/*
* https://codeforces.com/problemset/problem/271/A
*/
#include <bits/stdc++.h>
using namespace std;

bool func(int num)
{
    string s = to_string(num);
    int a[10] = {0, };

    for (int i= 0; i < s.size(); ++i)
        a[s[i] - '0']++;

    for (int i = 0; i < 10; ++i)
        if (a[i] > 1) return false;

    return true;
}

int main()
{
    int N;
    cin >> N;

    while (true)
    {
        if (func(++N))
        {
            cout << N;
            break;
        }
    }
}
