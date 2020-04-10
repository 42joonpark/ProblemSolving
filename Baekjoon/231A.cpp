/*
* https://codeforces.com/contest/231/problem/A
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, res = 0, a, b, c;
    cin >> N;
    
    for (int i = 0; i < N; ++i)
    {
        int ct = 0;
        cin >> a >> b >> c;
        
        a == 1 ? ct++ : ct += 0;
        b == 1 ? ct++ : ct += 0;
        c == 1 ? ct++ : ct += 0;
        
        ct >= 2 ? res++ : res += 0;
    }
    cout << res;
}
