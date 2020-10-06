#include <bits/stdc++.h>
using namespace std;

int N, sum;
int dx[8] = {-1, 1};
int dy[8] = {-1, -1};
int cols[15];

bool checkQueen(vector<vector<int>>& board, int y, int x)
{
    for (int i = 0; i < 2; ++i)
    {
        int newy = y, newx = x;
        bool found = false;
        while (true) {
            newy += dy[i];
            newx += dx[i];

            if (newx >= 0 && newy >= 0 && newx < N && newy < N)
            {
                if (board[newy][newx] == 1) {
                    found = true;
                    break;
                }
            }
            else 
                break;
        }
        if (found) return false;
    }
    return true;
}

void findQueen(vector<vector<int>>& board, int y)
{
    if (y >= N) return;

    for (int x = 0; x < N; ++x) {
        if (!cols[x]) {
            board[y][x] = 1;
            cols[x] = 1;
            bool check = checkQueen(board, y, x);
            if (check) {
                if (y == N - 1)
                    sum++;
                findQueen(board, y + 1);
            }
            cols[x] = 0;
            board[y][x] = 0;
        }
    }
}

int main()
{
    cin >> N;
    vector<vector<int>> board(N, vector<int>(N, 0));

    findQueen(board, 0);

    cout << sum << endl;
}