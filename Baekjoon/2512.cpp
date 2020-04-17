/*
* https://www.acmicpc.net/problem/2512
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M, st, ed;
    int m_val = 0, maxBud = 0;
    vector<int> budgets;

    cin >> N;
    budgets.resize(N);

    for (int i = 0; i < N; ++i) {
        scanf("%d", &budgets[i]);
        maxBud = max(maxBud, budgets[i]);
    }

    cin >> M;

    ed = maxBud + 1;
    st = 0;

    while (st < ed) {
        int mid = (st + ed) / 2;
        int sum = 0;

        for (int i = 0; i < budgets.size(); ++i) {
            sum += min(budgets[i], mid);
        }

        if (sum <= M) {
            m_val = max(m_val, mid);
            st = mid + 1;
        }
        else ed = mid;
    }
    cout << m_val;
}
