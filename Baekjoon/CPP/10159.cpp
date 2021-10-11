/*
* https://www.acmicpc.net/problem/10159
*/
#include <bits/stdc++.h>
using namespace std;

int N, M;
int visit[101][101];
void DFS(vector<vector<int> >& vec, int num)
{
    stack<int> s;
    s.push(num);
    visit[num][num] = true;

    while (!s.empty())
    {
        int cur = s.top();
        s.pop();

        for (int i = 0; i < vec[cur].size(); ++i)
        {
            int next = vec[cur][i];
            if (!visit[num][next])
            {
                s.push(next);
                visit[num][next] = true;
            }
        }
    }
}

int main()
{
    vector<vector<int> > light, heavy;

    cin >> N >> M;

    light.resize(N + 1);
    heavy.resize(N + 1);

    for (int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
        light[a].push_back(b);
        heavy[b].push_back(a);
    }

    for (int i = 1; i <= N; ++i)
    {
        DFS(light, i);
        DFS(heavy, i);
    }

    for (int i = 1; i <= N; ++i)
    {
        int ct = 0;
        for (int j = 1; j <= N; ++j)
        {
            if (!visit[i][j])
                ct++;
        }
        cout << ct << endl;
    }
}
