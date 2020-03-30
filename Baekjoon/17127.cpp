/*
* https://www.acmicpc.net/problem/17127
*/
#include <bits/stdc++.h>
using namespace std;

int A[10], N, sum, temp, tot = 1;
void func(int n, int idx, int total, int ts)
{
    if (n == 0)
    {
        ts += total;
        sum = max(sum, ts);
        return;
    }

    for (int i = idx; i < N - n; ++i)
    {
        temp = 1;
        for (int j = idx; j <= i; ++j)
            temp *= A[j];
        func(n - 1, i + 1, total / temp, ts + temp);
    }
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        tot *= A[i];
    }

    func(3, 0, tot, 0);

    cout << sum << endl;
}
