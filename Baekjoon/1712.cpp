/*
* https://www.acmicpc.net/problem/1712
*/

#include <bits/stdc++.h>
using namespace std;

long long A, B, C, S;

int main()
{
    cin >> A >> B >> C;
    S = C - B;
    //cout << S << endl;
    if (S <= 0) cout << -1 << endl;
    else cout << A / S + 1 << endl;
}
