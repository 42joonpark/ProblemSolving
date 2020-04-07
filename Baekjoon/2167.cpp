/*
* https://www.acmicpc.net/problem/2167
*/
#include <bits/stdc++.h>
using namespace std;

int arr[301][301];
int N, M, K, I, J, Y, X;
void getSum()
{
    for (int y = 1; y <= N; ++y)
        for (int x = 1; x <= M; ++x)
            arr[y][x] += (arr[y - 1][x] + arr[y][x - 1] - arr[y - 1][x - 1]);
}

int main()
{
    cin >> N >> M;

    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            cin >> arr[i][j];

    getSum();

    int sum, A, B, C, D;
    for (cin >> K; K > 0; --K)
    {
        cin >> I >> J >> Y >> X;

        sum = arr[Y][X];
        A = arr[I - 1][X];
        B = arr[Y][J - 1];
        C = arr[I - 1][J - 1];
        D = A + B - C;

        sum = sum - D;
        cout << sum << endl;
    }
}
