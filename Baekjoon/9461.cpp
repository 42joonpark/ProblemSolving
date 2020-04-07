/*
* https://www.acmicpc.net/problem/9461
*/
#include <bits/stdc++.h>
using namespace std;

long long int padovan[101];
int main()
{
    padovan[1] = 1;
    padovan[2] = 1;
    padovan[3] = 1;
    padovan[4] = 2;
    padovan[5] = 2;

    for (int i = 6; i <= 100; ++i)
        padovan[i] = padovan[i - 1] + padovan[i - 5];

    int t, n;
    for (cin >> t; t > 0; --t)
    {
        cin >> n;
        cout << padovan[n] << endl;
    }
}
