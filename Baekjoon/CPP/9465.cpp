/*
* https://www.acmicpc.net/problem/9465
*/
#include <bits/stdc++.h>
using namespace std;

int R[3][100001];
int n, t;
int main()
{
    cin >> t;
    while (t--)
    {
        vector<int> UP, DOWN;
        int M = 0;

        cin >> n;
        UP.resize(n);
        DOWN.resize(n);
        memset(R, 0, sizeof(R));

        for (int i = 0; i < n; ++i)
            cin >> UP[i];
        for (int i = 0; i < n; ++i)
            cin >> DOWN[i];

        R[0][0] = 0;
        R[1][0] = UP[0]; // 처음만 이렇게 진행 
        R[2][0] = DOWN[0]; // 마찬가지

        for (int i = 1; i < UP.size(); ++i)
        {
            R[0][i] = max(R[1][i - 1], R[2][i - 1]);
            M = max(M, R[0][i]);

            R[1][i] += max(R[2][i - 1], R[0][i - 1]); // 위는 이전 대각선 아래의 값 사용
            R[1][i] += UP[i];
            M = max(M, R[1][i]);

            R[2][i] += max(R[1][i - 1], R[0][i - 1]); // 아래는 이전 대각선 위의 값 사용
            R[2][i] += DOWN[i];
            M = max(M, R[2][i]);
        }

        cout << M << endl;
    }
}
