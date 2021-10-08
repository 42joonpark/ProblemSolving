/*
* https://www.acmicpc.net/problem/14501
*/
#include <bits/stdc++.h>
using namespace std;

int T[20], P[20], sum[20];
int main()
{
    int N;
    cin >> N;
    
    for (int i = 1; i <= N; ++i)
    {
        int t, p;
        cin >> t >> p;
        T[i] = t;
        P[i] = p;
    }
    
    for (int i = 1; i <= N; ++i)
    {
        sum[i] = max(sum[i], sum[i - 1]);
        sum[i + T[i]] = max(sum[i + T[i]], sum[i] + P[i]);
    }
    sum[N + 1] = max(sum[N + 1], sum[N]);
    
    cout << sum[N + 1];
}
