/*
* https://www.acmicpc.net/problem/2294
*/
#include <bits/stdc++.h>
using namespace std;

int n, k;
int coin[101], cache[10001];
int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> coin[i];
    
    for (int i = 1; i <= k; ++i)
        cache[i] = INT_MAX - 1;
    
    sort(coin, coin + n);
    for (int i = 0; i < n; ++i)
        for (int t = coin[i]; t <= k; ++t)
            cache[t] = min(cache[t], cache[t - coin[i]] + 1);

    if (cache[k] == INT_MAX - 1) cout << -1;
    else cout << cache[k];
}
