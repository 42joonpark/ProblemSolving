/*
* https://www.acmicpc.net/problem/2252
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
    queue<int> q;

    for (int i = 0; i < M; ++i) {
        cin >> A >> B;
        count[B]++;
        vec[A].push_back(B);
    }

    for (int i = 1; i <= N; ++i) {
        if (count[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        cout << cur << " ";

        for (int i = 0; i < vec[cur].size(); ++i) {
            if (--count[vec[cur][i]] == 0) {
                q.push(vec[cur][i]);
            }
        }
    }
}
