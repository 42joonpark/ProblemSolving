/*
* https://www.acmicpc.net/problem/2292
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, V = 1, T = 6, S = 6, ct = 1;
    cin >> N;

    while (true)
    {
        if (N <= V)
            break;
        V += S;
        S += T;
        ct++;
    }
    cout << ct << endl;
}
