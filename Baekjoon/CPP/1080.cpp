/*
* https://www.acmicpc.net/problem/1080
*/
#include <bits/stdc++.h>
using namespace std;

int from[50][50], to[50][50];
int n, m, res = 0;

bool check()
{
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (from[i][j] != to[i][j]) return false;
    return true;
}

void func()
{
    for (int i = 0; i < n - 2; ++i) {
        for (int j = 0; j < m - 2; ++j) {
            if (from[i][j] != to[i][j]) {
                for (int k = 0; k < 3; ++k) {
                    for (int p = 0; p < 3; ++p) {
                        if (i + k < n && j + p < m) {
                            from[i + k][j + p] = from[i + k][j + p] == 1 ? 0 : 1;
                        }
                    }
                }
                res++;
            }
            if (check()) return;
        }
    }
}

int main()
{
    cin >> n >> m;
    
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            scanf("%1d", &from[i][j]);
            
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            scanf("%1d", &to[i][j]);
            
    func();
    if (!check()) cout << -1;
    else cout << res;
}
