/*
* https://www.acmicpc.net/problem/3109
*/
#include <bits/stdc++.h>
using namespace std;

vector<string> vec;
bool vis[10001][501];
int R, C;
int dy[3] = {-1, 0, 1};
int dx[3] = {1, 1, 1};

bool dfs(int y, int x)
{
    vis[y][x] = true;
    if (x == C - 1) 
        return true;

    bool succ = false;
    for (int i = 0; i < 3; ++i) {
        int newy = y + dy[i];
        int newx = x + dx[i];

        if (newy >= 0 && newy < R && newx < C && newx >= 0 && !vis[newy][newx]) {
            succ = dfs(newy, newx);

            if (succ) return true;
        }
    }
    vec[y][x] = false;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int ct = 0;
    cin >> R >> C;

    vec.resize(R);
    for (int i = 0; i < R; ++i) {
        cin >> vec[i];

        for (int j = 0; j < vec[i].size(); ++j) {
            vis[i][j] = vec[i][j] == '.' ? 0 : 1;
        }
    }

    for (int i = 0; i < R; ++i) {
        bool succ;
        succ = dfs(i, 0);

        if (succ) ct++;
    }
    cout << ct;
}
