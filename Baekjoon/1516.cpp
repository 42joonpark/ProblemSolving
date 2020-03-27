/*
* https://www.acmicpc.net/problem/1516
*/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > vec(501);
vector<int> ct(501, 0);
vector<int> total(501, 0);
vector<int> dur(501, 0);
queue<int> q;

int main()
{
    int N;
    cin >> N;

    for (int i = 1; i <= N; ++i) {
        int num;
        cin >> dur[i];
        while (true) {
            cin >> num;
            if (num == -1) break;
            ct[i]++;
            vec[num].push_back(i);
        }
    }

    for (int i = 1; i <= N; ++i) {
        if (ct[i] == 0)
            q.push(i);
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        total[cur] += dur[cur];
        for (int i = 0; i < vec[cur].size(); ++i) {
            int next = vec[cur][i];

            total[next] = max(total[next], total[cur]);

            if (--ct[next] == 0) {
                q.push(next);
            }
        }
    }
    for (int i = 1; i <= N; ++i)
        cout << total[i] << endl;
}
