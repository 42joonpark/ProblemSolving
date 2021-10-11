/*
* https://www.acmicpc.net/problem/11057
*/
#include <bits/stdc++.h>
using namespace std;

int R[1001][10];
int sum;
int main()
{
    int N;
    cin >> N;

    for (int i = 0; i < 10; ++i)
        R[1][i] = 1;

    for (int i = 2; i <= N; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            for (int k = j; k < 10; ++k)
            {
                R[i][j] += R[i - 1][k];
                R[i][j] %= 10007;
            }
        }
    }

    for (int i = 0; i < 10; ++i)
        sum += R[N][i];
    
    cout << sum % 10007;
}
