/*
* https://www.acmicpc.net/problem/2146
*/
#include <bits/stdc++.h>
using namespace std;

int N;
int dy[4] = {0, -1, 0, 1};
int dx[4] = {-1, 0, 1, 0};
int land[101][101];
int visit[101][101];
void bfs(int Y, int X, int islandNum)
{
    queue<pair<int, int> > q;
    q.push(make_pair(Y, X));
    land[Y][X] = islandNum;

    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int newy = y + dy[i];
            int newx = x + dx[i];

            if (newx >= 0 && newy >= 0 && newx < N && newy < N && land[newy][newx] == 1)
            {
                land[newy][newx] = islandNum;
                q.push(make_pair(newy, newx));
            }
        }
    }
}

int BFS(int Y, int X, int islandNum)
{
    int Min = INT_MAX;
    queue<pair<int, pair<int, int> > > q;
    q.push(make_pair(0, make_pair(Y, X)));

    while (!q.empty())
    {
        int y = q.front().second.first;
        int x = q.front().second.second;
        int ct = q.front().first;
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int newy = y + dy[i];
            int newx = x + dx[i];

            if (newx >= 0 && newy >= 0 && newx < N && newy < N)
            {
                if (land[newy][newx] == 0 && !visit[newy][newx])
                {
                    visit[newy][newx] = true;
                    q.push(make_pair(ct + 1, make_pair(newy, newx))); 
                }
                else if (land[newy][newx] != 0 && land[newy][newx] != islandNum)
                {
                    return ct;
                }
            }
        }
    }

    return Min;
}

int main()
{
    int islandNum = 2;
    int res = INT_MAX;
    cin >> N;

    for (int y = 0; y < N; ++y)
        for (int x = 0; x < N; ++x)
            cin >> land[y][x];

    // initialize
    for (int y = 0; y < N; ++y)
        for (int x = 0; x < N; ++x)
            if (land[y][x] == 1)
                bfs(y, x, islandNum++);

    for (int y = 0; y < N; ++y)
    {
        for (int x = 0; x < N; ++x)
        {
            for (int i = 0; i < N; ++i)
                for (int j = 0; j < N; ++j)
                    visit[i][j] = false;

            if (land[y][x] > 0)
                res = min(res, BFS(y, x, land[y][x]));
        }
    } 

    cout << res;
}
