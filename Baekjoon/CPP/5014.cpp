/*
* https://www.acmicpc.net/problem/5014
*/
#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000001;
int dp[MAX];
int F, S, G, U, D;
void dfs(int cur)
{
    int next = cur + U;
    int before = cur - D;

    if (next <= F && dp[next] > dp[cur] + 1)
    {
        dp[next] = dp[cur] + 1;
        dfs(next);
    }

    if (before > 0 && dp[before] > dp[cur] + 1)
    {
        dp[before] = dp[cur] + 1;
        dfs(before);
    }
}

int main()
{
    cin >> F >> S >> G >> U >> D;

    for (int i = 0; i <= F; ++i)
        dp[i] = INT_MAX;

    dp[S] = 0;
    dfs(S);

    if (dp[G] != INT_MAX)
        cout << dp[G];
    else 
        cout << "use the stairs";
}
