/*
* https://www.acmicpc.net/problem/11053
*/
#include <bits/stdc++.h>
using namespace std;

int dp[1001], n, m, MAX;
int main()
{
    cin >> n;

    vector<int> num(n);
    for (int i = 0; i < n;++i) 
    {
        cin >> num[i];

        m = 0;
        for (int j = 0; j < i; ++j)
        {
            if (num[i] > num[j])
                m = max(dp[j], m);
        }

        dp[i] = m + 1;
        MAX = max(MAX, dp[i]);
    }

    cout << MAX << endl;
}
