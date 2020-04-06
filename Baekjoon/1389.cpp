/*
* https://www.acmicpc.net/problem/1389
*/
#include <bits/stdc++.h>
using namespace std;

vector<bool> visit;
vector<vector<int> > vec;
int sum[101][101];
int res = INT_MAX, ans = 1, N, M;

int bfs(int num)
{
    int M = 0;
    queue<pair<int, int> > q;
    q.push(make_pair(num, 0));
    visit[num] = true;

    while (!q.empty())
    {
        int cur = q.front().first;
        int ct = q.front().second;
        q.pop();
        M = max(M, ct);

        for (int i = 0; i < vec[cur].size(); ++i)
        {
            int next = vec[cur][i];
            if (!visit[next])
            {
                sum[num][next] = ct + 1;
                q.push(make_pair(next, ct + 1));
                visit[next] = true;
            }
        }
    }

    return M;
}

int main()
{
    cin >> N >> M;
    vec.resize(N + 1);
    visit.resize(N + 1);
    for (int i = 0; i < M; ++i)
    {
        int n1, n2;
        cin >> n1 >> n2;

        vec[n1].push_back(n2);
        vec[n2].push_back(n1);
    }

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
            visit[j] = false;
        bfs(i);
    }

    for (int i = 1; i <= N; ++i)
    {
        int total = 0;
        for (int j = 1; j <= N; ++j)
        {
            total += sum[i][j];    
        }

        if (total < res)
        {
            ans = i;
            res = total;
        }
    }

    cout << ans;
}
