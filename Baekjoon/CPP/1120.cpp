/*
* https://www.acmicpc.net/problem/1120
*/
#include <bits/stdc++.h>
using namespace std;

string A, B;
int m_min;
int main()
{
    cin >> A >> B;
    for (int i = 0; i < A.size(); ++i)
        if (A[i] != B[i]) m_min++;

    for (int i = 0; i <= B.size() - A.size(); ++i) {
        int ct = 0;
        for (int j = 0; j < A.size(); ++j) {
            if (A[j] != B[i + j]) ct++;
        }
        m_min = min(m_min, ct);
    }
    cout << m_min;
}
