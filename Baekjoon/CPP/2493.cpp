/*
* https://www.acmicpc.net/problem/2493
*/
#include <bits/stdc++.h>
using namespace std;

int num[500001], ans[500001], N;
stack<pair<int, int> > s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 1; i <= N; ++i)
        cin >> num[i]; 

    for (int i = N; i >= 1; --i)
    {
        int cur = num[i];
        while (!s.empty() && s.top().first <= cur)
        {
            ans[s.top().second] = i;
            s.pop();
        }
        s.push(make_pair(cur, i));
    }

    for (int i = 1; i <= N; ++i)
        cout << ans[i] << " ";
}
