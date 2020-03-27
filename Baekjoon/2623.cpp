/*
* https://www.acmicpc.net/problem/2623
*/
#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int> > singers;
vector<int> counts;
queue<int> turn;

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    singers.resize(N + 1);
    counts.resize(N + 1);

    for (int i = 1; i <= M; ++i) {
        int n;
        vector<int> temp;
        cin >> n;

        temp.resize(n);
        for (int j = 0; j < n; ++j)
            cin >> temp[j];

        for (int j = 1; j < temp.size(); ++j) {
            int b = temp[j - 1];
            int c = temp[j];

            counts[c]++;
            singers[b].push_back(c);
        }
    }

    for (int i = 1; i <= N; ++i) {
        if (counts[i] == 0)
            turn.push(i);
    }

    vector<int> res;
    while (!turn.empty()) {
        int cur = turn.front();
        turn.pop();
        res.push_back(cur);

        for (int i = 0; i < singers[cur].size(); ++i) {
            int next = singers[cur][i];
            if (--counts[next] == 0) {
                turn.push(next);
            }
        }
    }

    for (int i = 1; i <= N; ++i) 
        if (counts[i] != 0) {
            cout << 0 << endl;
            return 0;
        }

    for (auto& a : res)
    cout << a << endl;
}
