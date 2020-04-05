/*
* https://www.acmicpc.net/problem/2908
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s1, s2, ans;
    cin >> s1 >> s2;
    
    for (int i = s1.size() - 1; i >= 0; --i)
    {
        if (s1[i] > s2[i])
        {
            ans = string(s1.rbegin(), s1.rend());
            break;
        }
        else if (s1[i] < s2[i])
        {
            ans = string(s2.rbegin(), s2.rend());
            break;
        }
    }
    
    cout << ans;
}
