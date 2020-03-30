/*
* https://www.acmicpc.net/problem/4811
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll dp[31][31];
ll init(int w, int h)
{
    if (w < 0 || h < 0) return 0;
    if (w == 0) return 1;

    ll val = dp[w][h];
    if (val != 0) return val;
    return dp[w][h] = init(w, h - 1) + init(w - 1, h + 1);
}

int main()
{
    init(30, 0);

    int num;
    while (true)
    {
        cin >> num;
        if (num == 0) break;

        cout << dp[num][0] << endl;
    }
}
