/*
* https://www.acmicpc.net/problem/1946
*/
#include <bits/stdc++.h>
using namespace std;

int t, N;
int main()
{
    cin >> t;
    while (t--) {
        int best, ct = 0, m_min = INT_MAX;
        cin >> N;
        vector<pair<int, int> > vec(N);

        for (int i = 0; i < N; ++i)
            cin >> vec[i].first >> vec[i].second;

        sort(vec.begin(), vec.end());

        for (int i = 0; i < vec.size(); ++i) {
            if (vec[i].second <= m_min) {
                m_min = min(m_min, vec[i].second);
                ct++;
            }
        }

        cout << ct << endl;
    } 
}
