/*
* https://www.acmicpc.net/problem/11048
*/
#include <bits/stdc++.h>
using namespace std;

int dy[3] = {1, 0, 1};
int dx[3] = {0, 1, 1};
int miz[1001][1001];
int C[1001][1001];
int vis[1001][1001];
int N, M;

void bfs(int Y, int X)
{
    queue<pair<int, int> > q;
    q.push(make_pair(Y, X));
    vis[Y][X] = 1;

    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        int val = C[y][x];
        q.pop();

        for (int i = 0; i < 3; ++i)
        {
            int newy = y + dy[i];
            int newx = x + dx[i];

            if (newx >= 1 && newy >= 1 && newx <= M && newy <= N)
            {
                int newVal = val + miz[newy][newx];
                if (newVal > C[newy][newx])
                {
                    C[newy][newx] = newVal;
                }

                if (!vis[newy][newx])
                {
                    vis[newy][newx] = 1;
                    q.push(make_pair(newy, newx));
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for (int y = 1; y <= N; ++y)
        for (int x = 1; x <= M; ++x)
            cin >> miz[y][x];

    C[1][1] = miz[1][1];

    bfs(1, 1);

    cout << C[N][M];
}
