/*
* https://www.acmicpc.net/problem/2573
*/
#include <bits/stdc++.h>
using namespace std;

int m[301][301], W, H, year;
bool visit[301][301];
int dy[4] = {0, -1, 0, 1};
int dx[4] = {-1, 0, 1, 0};

void melt()
{
    int temp[301][301];
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            temp[i][j] = m[i][j];
    
    for (int y = 1; y < H - 1; ++y)
    {
        for (int x = 1; x < W - 1; ++x)
        {
            if (temp[y][x] > 0)
            {
                for (int i = 0; i < 4; ++i)
                {
                    int newy = y + dy[i];
                    int newx = x + dx[i];

                    if (newx >= 0 && newy >= 0 && newx < W && newy < H && temp[newy][newx] == 0)
                    {
                        if (m[y][x] > 0)
                            m[y][x]--;
                    }
                }
            }
        }
    }
}

void bfs(int Y, int X)
{
    queue<pair<int, int> > q;
    q.push(make_pair(Y, X));

    visit[Y][X] = true;
    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int newy = y + dy[i];
            int newx = x + dx[i];

            if (newx >= 0 && newy >= 0 && newx < W && newy < H && m[newy][newx] > 0 && !visit[newy][newx])
            {
                q.push(make_pair(newy, newx));
                visit[newy][newx] = true;
            }
        }
    }
}

int main()
{
    cin >> H >> W;
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            cin >> m[i][j];

    while (true)
    {
        memset(visit, 0, sizeof(visit));

        int ice_ct = 0, water = 0;
        for (int y = 1; y < H - 1; ++y)
            for (int x = 1; x < W - 1; ++x)
            {
                if (m[y][x] > 0 && !visit[y][x])
                {
                    ice_ct++;
                    bfs(y, x);

                    if (ice_ct >= 2) {
                        cout << year;
                        return 0;
                    }
                }
            }

        if (ice_ct == 0) break;
        melt();
        year++;
    }

    cout << 0;
}
