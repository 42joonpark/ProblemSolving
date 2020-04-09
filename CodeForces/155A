/*
* https://codeforces.com/problemset/problem/155/A
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> a;
    int N, m_min, m_max, ct = 0;
    cin >> N;
    a.resize(N);

    for (int i = 0; i < N; ++i)
        cin >> a[i];

    m_min = m_max = a[0];

    for (int i = 1; i < N; ++i)
    {
        if (a[i] > m_max) {
            ct++;
            m_max = a[i];
        }
        if (a[i] < m_min) {
            ct++;
            m_min = a[i];
        }
    }
    cout << ct;
}
