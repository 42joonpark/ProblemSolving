/*
* https://www.acmicpc.net/problem/1699
*/
#include <bits/stdc++.h>
using namespace std;

int cache[100001];
int main()
{
    int N;
    cin >> N;

    cache[1] = 1;
    for (int i = 2; i <= N; ++i)
    {
        int s = sqrt(i);
        if (i == (s * s)) cache[i] = 1;
        else
        {
            int temp = i;
            int M = INT_MAX;
            
            for (int t = s; t >= 1; --t)
            {
                int tot = 0;
                int cur = t * t;
                int res = temp - cur;

                tot = cache[cur] + cache[res];
                M = min(M, tot);
            }
            cache[i] = M;
        }
    }

    cout << cache[N];
}
