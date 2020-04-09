/*
* https://www.acmicpc.net/problem/14888
*
#include <bits/stdc++.h>
using namespace std;

int m_max = INT_MIN, m_min = INT_MAX;
int R[4], a[11], N;

void func(int sum, int op, int idx)
{ 
    if (op == 0) {
        sum += a[idx];
    } else if (op == 1) {
        sum -= a[idx];
    } else if (op == 2) {
        sum *= a[idx];
    } else if (op == 3) {
        if (a[idx] == 0) return;
        sum /= a[idx];
    }
    
    if (idx == N - 1) {
        m_max = max(m_max, sum);
        m_min = min(m_min, sum);
        return;
    }
    
    for (int i = 0; i < 4; ++i)
    {
        if (R[i] > 0)
        {
            R[i]--;
            func(sum, i, idx + 1);
            R[i]++;
        }
    }
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> a[i];
    
    cin >> R[0] >> R[1] >> R[2] >> R[3];
    
    func(a[0], -1, 0);
    
    cout << m_max << '\n' << m_min;
}
