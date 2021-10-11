/*
* https://www.acmicpc.net/problem/7568
*/
#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int> > vec;
int ans[51];
int main()
{
    int N;
    cin >> N;
    vec.resize(N);
    
    for (int i = 0; i < N; ++i)
        cin >> vec[i].first >> vec[i].second;
    
    for (int i = 0; i < vec.size(); ++i)
    {
        int ct = 0;
        for (int j = 0; j < vec.size(); ++j)
        {
            if (vec[i].first <vec[j].first && vec[i].second < vec[j].second)
                ct++;
        }
        ct++;
        ans[i] = ct;
    }
    
    for (int i = 0; i < N; ++i)
        cout << ans[i] << " ";
}
