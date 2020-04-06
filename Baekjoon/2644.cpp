/*
* https://www.acmicpc.net/problem/2644
*/ 
#include <bits/stdc++.h>
using namespace std;

int n, m, f, s, x, y, res = INT_MAX;
int parent[101];

void dfs(vector<int>& vec, int p)
{
    if (parent[p] == p)
        return;
    
    p = parent[p];
    vec.push_back(p);
    dfs(vec, p);
}

int main()
{
    cin >> n >> f >> s >> m;
    for (int i = 1; i <= n; ++i)   
        parent[i] = i;

    for (int i = 0; i < m; ++i)
    {
        cin >> x >> y;
        parent[y] = x;
    }

    if (f == s) 
    {
        cout << 0 ;
        return 0;
    }

    vector<int> f1, f2;
    f1.push_back(f);
    f2.push_back(s);
    dfs(f1, f);
    dfs(f2, s);

    bool found = false;
    for (int i = 0; i < f1.size(); ++i)
        for (int j = 0; j < f2.size(); ++j)
            if (f1[i] == f2[j])
            {
                found = true;
                res = min(res, i + j);
            }

    if (found) cout << res;
    else cout << -1;
}
