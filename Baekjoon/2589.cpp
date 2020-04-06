/*
* https://www.acmicpc.net/problem/2589
*/
#include <bits/stdc++.h>
using namespace std;

int W, H, M;
int dy[4] = {0, -1, 0, 1};
int dx[4] = {-1, 0, 1, 0};
int temp[51][51];
vector<string> island(51);

int bfs(int Y, int X)
{
    memset(temp, -1, sizeof(temp));

    queue<pair<int, int> > q;
    int res = 0;

    q.push(make_pair(Y, X));
    temp[Y][X] = 0;

    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int newy = y + dy[i];
            int newx = x + dx[i];

            res = max(res, temp[y][x]);

            if (newx >= 0 && newx < W && newy >= 0 && newy < H)
            {
                if (island[newy][newx] == 'L' && temp[newy][newx] == -1)
                {
                    q.push(make_pair(newy, newx));
                    temp[newy][newx] = temp[y][x] + 1;
                }
            }
        }
    }

    return res;
}

int main()
{
    island.resize(51);

    cin >> H >> W;
    for (int y = 0; y < H; ++y)
        cin >> island[y];
    
    for (int y = 0; y < H; ++y)
    {
        for (int x = 0; x < W; ++x)
        {
            if (island[y][x] == 'L')
                M = max(M, bfs(y, x)); 
        }
    }

    cout << M;
}
