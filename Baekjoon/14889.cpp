/*
* https://www.acmicpc.net/problem/14889
*/
#include <bits/stdc++.h>
using namespace std;

bool check[21];
int p[21][21];
int N, m_min = INT_MAX;

void calcAb()
{
    vector<int> A, B;
    int a = 0, b = 0;
    for (int i = 0; i < N; ++i)
        if (check[i]) A.push_back(i);
        else B.push_back(i);

    for (int i = 0; i < A.size(); ++i)
        for (int j = 0; j < A.size(); ++j)
            a += p[A[i]][A[j]];
    for (int i = 0; i < B.size(); ++i)
        for (int j = 0; j < B.size(); ++j)
            b += p[B[i]][B[j]];

    m_min = min(m_min, abs(a - b));
}

void func(int c, int n)
{
    if (n == N / 2)
    {
        calcAb();
        return;
    }

    for (int i = c; i < N; ++i)
    {
        if (!check[i])
        {
            check[i] = true;
            func(i + 1, n + 1);
            check[i] = false;
        }
    }
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> p[i][j];

    func(0, 0);

    cout << m_min;
}
