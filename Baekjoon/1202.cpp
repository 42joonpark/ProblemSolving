/*
* https://www.acmicpc.net/problem/1202
*/
#include <bits/stdc++.h>
using namespace std;

int n, k;
long long int ans;
vector<pair<int, int> > J;
vector<int> B;
priority_queue<int> q;

int main()
{
    cin >> n >> k;
    J.resize(n);
    B.resize(k);

    for (int i = 0; i < n; ++i)
        cin >> J[i].first >> J[i].second;

    for (int i = 0; i < k; ++i)
        cin >> B[i];

    sort(J.begin(), J.end());
    sort(B.begin(), B.end());

    int idx = 0;
    for (int i = 0; i < k; ++i) {
        while (idx < n && J[idx].first <= B[i])
            q.push(J[idx++].second);

        if (!q.empty()) {
            ans += q.top();
            q.pop();
        }
    }
    cout << ans;

}
