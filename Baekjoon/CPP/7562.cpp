/*
* https://www.acmicpc.net/problem/7562
*/
#include <bits/stdc++.h>
using namespace std;

int dy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
bool visit[300][300];
int res, t, I;

void bfs(queue<pair<int, pair<int,int> > >& q, pair<int, int>& destination)
{
    while (!q.empty()) 
    {
        int cur = q.front().first;
        int y = q.front().second.first;
        int x = q.front().second.second;
        q.pop();

        for (int i = 0; i < 8; ++i)
        {
            int newy = y + dy[i];
            int newx = x + dx[i];

            if (newx >= 0 && newy >= 0 && newx < I && newy < I && !visit[newy][newx])
            {
                if (destination.first == newy && destination.second == newx)
                {
                    res = cur;
                    return;
                }
                q.push(make_pair(cur + 1, make_pair(newy, newx)));
                visit[newy][newx] = 1;
            }
        }
    }
}

int main()
{
    int sy, sx, dy, dx;
    for (cin >> t; t > 0; --t) 
    {
        queue<pair<int, pair<int, int> > > q;
        cin >> I >> sy >> sx >> dy >> dx;
        res = 0;

        memset(visit, 0, sizeof(visit));
        pair<int, int> start(sy, sx);
        pair<int, int> end(dy, dx);

        if (start != end)
        {
            visit[sy][sx] = true;
            q.push(make_pair(1, start));
            bfs(q, end);
        }

        cout << res << endl;
    }
}
