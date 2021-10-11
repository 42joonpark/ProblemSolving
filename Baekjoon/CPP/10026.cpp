/*
* https://www.acmicpc.net/problem/10026
*/
#include <bits/stdc++.h>
using namespace std;

vector<string> rgb, rb;
int visit[101][101], N, R, G, B;
int dy[4] = {0, -1, 0, 1};
int dx[4] = {-1, 0, 1, 0};

void DFS(vector<string>& vec, int Y, int X, char c)
{
    stack<pair<int, int> > s;
    s.push(make_pair(Y, X));
    visit[Y][X] = 1;

    while (!s.empty())
    {
        int y = s.top().first;
        int x = s.top().second;
        s.pop();

        for (int i = 0; i < 4; ++i)
        {
            int newy = y + dy[i];
            int newx = x + dx[i];

            if (newx >= 0 && newy >= 0 && newx < N && newy < N)
            {
                char t = vec[newy][newx];
                int v = visit[newy][newx];
                if (t == c && v == 0)
                {
                    visit[newy][newx] = 1;
                    s.push(make_pair(newy, newx));
                }
            }
        }
    }
}

int main()
{
    cin >> N;
    rgb.resize(N);
    rb.resize(N);

    for (int i = 0; i < N; ++i)
        cin >> rgb[i];
    
    rb = rgb;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (rb[i][j] == 'G')
                rb[i][j] = 'R';

    memset(visit, 0, sizeof(visit));

    int ct = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (visit[i][j] == 0)
            {
                DFS(rgb, i, j, rgb[i][j]);
                ct++;
            }
        }
    }

    memset(visit, 0, sizeof(visit));

    int ct_ct = 0;
    for (int i = 0; i < rb.size(); ++i)
    {
        for (int j = 0; j < rb[i].size(); ++j)
        {
            if (!visit[i][j])
            {
                DFS(rb, i, j, rb[i][j]);
                ct_ct++;
            }
        }
    }
    cout << ct << " " << ct_ct << endl;
}
