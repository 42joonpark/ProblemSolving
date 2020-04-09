/*
* https://www.acmicpc.net/problem/13460
*/
#include <bits/stdc++.h>
using namespace std;

struct node {
    int ry, rx, by, bx, dis;
};

int H, W;
int dy[4] = {0, -1, 0, 1};
int dx[4] = {-1, 0, 1, 0};
char board[10][10];
bool vis[10][10][10][10];
queue<node> q;

void Move(int& y, int& x, int& c, int dy, int dx)
{
    while (board[y + dy][x + dx] != '#' && board[y][x] != 'O')
    {
        y += dy;
        x += dx;
        c += 1;
    }
}

void bfs()
{
    while (!q.empty())
    {
        struct node Node = q.front();
        int rx = Node.rx, ry = Node.ry;
        int bx = Node.bx, by = Node.by;
        int d = Node.dis;
        q.pop();
        if (d >= 10) break;

        for (int i = 0; i < 4; ++i)
        {
            int nrx = rx, nry = ry;
            int nbx = bx, nby = by;
            int rd = 0, bd = 0, nd = d + 1;
            Move(nry, nrx, rd, dy[i], dx[i]);
            Move(nby, nbx, bd, dy[i], dx[i]);
            if (board[nby][nbx] == 'O')
                continue; if (board[nry][nrx] == 'O')
            {
                cout << nd;
                return;
            }
            

            if (nry == nby && nrx == nbx)
            {
                if (rd > bd)
                {
                    nry -= dy[i];
                    nrx -= dx[i];
                }
                else
                {
                    nby -= dy[i];
                    nbx -= dx[i];
                }
            }

            if (vis[nry][nrx][nby][nbx]) continue;
            vis[nry][nrx][nby][nbx] = true;
            q.push({nry, nrx, nby, nbx, nd});
        }
    }
    cout << -1;
}

int main()
{
    int ry, rx, by, bx;

    scanf("%d %d", &H, &W);

    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            scanf("%1s", &board[i][j]);
            if (board[i][j] == 'R') ry = i, rx = j;
            else if (board[i][j] == 'B') by = i, bx = j;
        }
    }
    q.push({ry, rx, by, bx, 0});
    vis[ry][rx][by][bx] = true;
    bfs();
}
