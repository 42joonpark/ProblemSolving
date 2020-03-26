/*
* https://www.acmicpc.net/problem/1766
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, A, B;
    cin >> N >> M;

    vector<vector<int> > vec(N + 1);
    vector<int> count(N + 1, 0);
    priority_queue<int, vector<int>, greater<int> > q;

    for (int i = 0; i < M; ++i) {
        cin >> A >> B;
        count[B]++;
        vec[A].push_back(B);
    }

    for (int i = 1; i <= N; ++i) {
        if (count[i] == 0)
            q.push(i);
    }

    while (!q.empty()) {
        int cur = q.top();
        q.pop();

        cout << cur << " ";

        for (int i = 0; i < vec[cur].size(); ++i) {
            int next = vec[cur][i];

            if (--count[next] == 0)
                q.push(next);
        }
    }
}
