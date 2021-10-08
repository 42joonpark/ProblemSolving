/*
* https://www.acmicpc.net/problem/1969
*/
#include <bits/stdc++.h>
using namespace std;

int a[26], N, M, ct;
vector<string> vec;
string ans = "";
int main()
{
    cin >> N >> M;
    vec.resize(N);

    for (int i = 0; i < N; ++i)
        cin >> vec[i];

    for (int i = 0; i < M; ++i) {
        memset(a, 0, sizeof(a));

        for (int j = 0; j < N; ++j) {
            char t = vec[j][i];

            a[t - 'A']++;
        }

        int m_max = 0;
        char c;
        for (int k = 0; k < 26; ++k) {
            if (a[k] > m_max) {
                m_max = a[k];
                c = k + 'A';
            }
        }

        ct += (N - m_max);
        ans += c;
    }

    cout << ans << '\n' << ct;
}
