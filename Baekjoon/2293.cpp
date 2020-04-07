/*
* https://www.acmicpc.net/problem/2293
*/
#include <bits/stdc++.h>
using namespace std;

int n, k;
int nums[101], cache[10001];
int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> nums[i];
    
    cache[0] = 1;
    for (int i = 0; i < n; ++i)
        for (int t = nums[i]; t <= k; ++t)
            cache[t] += cache[t - nums[i]];

    cout << cache[k];
}
