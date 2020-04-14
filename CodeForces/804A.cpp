/*
* https://codeforces.com/problemset/problem/804/A
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    n % 2 == 0 ? cout << n / 2 - 1 : cout << n / 2;
}
