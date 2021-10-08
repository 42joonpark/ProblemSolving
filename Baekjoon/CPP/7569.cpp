/*
* https://www.acmicpc.net/problem/7569
*/
#include <bits/stdc++.h>
using namespace std;

int N, M, H, ct = 0, mct = 0, res = 0;
int board[10001][101];

void Do(queue<pair<int, int> >& q, int y, int x)
{
    board[y][x] = 1;
    q.push(make_pair(y, x));
    ct--;
}

void bfs(queue<pair<int, int> >& q1)
{
    int y, x;

    while (true) 
    {
        queue<pair<int, int> > q2;
        while (!q1.empty())
        {
            int Y = q1.front().first;
            int X = q1.front().second;
            q1.pop();

            // check left
            y = Y;
            x = X - 1;
            if (x >= 0 && board[y][x] == 0)
                Do(q2, y, x);
            // check right
            x = X + 1;
            if (x < M && board[y][x] == 0)
                Do(q2, y, x);

            // check front
            y = Y + 1;
            x = X;
            if (y < N * H && Y % N < y % N && board[y][x] == 0)
                Do(q2, y, x);

            // check back
            y = Y - 1;
            if (y >= 0 && Y % N > y % N && board[y][x] == 0)
                Do(q2, y, x);

            // check up
            y = Y + N;
            if (y < N * H && board[y][x] == 0)
                Do(q2, y, x);

            // check bottom
            y = Y - N;
            if (y >= 0 && board[y][x] == 0)
                Do(q2, y, x);
        }
        res++;
        if (q2.empty()) return;
        q1 = q2;
    }
}

int main()
{
    queue<pair<int, int> > q;
    cin >> M >> N >> H;
    for (int i = 0; i < N * H; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> board[i][j];
            if (board[i][j] == 1) {
                q.push(make_pair(i, j));
            }
            else if (board[i][j] == 0)
                ct++;
        }
    }

    bfs(q);

    if (ct > 0) cout << -1;
    else cout << --res << endl;
}
