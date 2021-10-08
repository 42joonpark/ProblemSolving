/*
* https://www.acmicpc.net/problem/11726
*/
#include <bits/stdc++.h>
using namespace std;

int n;
int main()
{
    cin >> n;

    int b = 1;
    int c = 2;
    int ans;

    if (n < 3) ans = n;

    for (int i = 3; i <= n; ++i)
    {
        ans = (b + c) % 10007;
        b = c;
        c = ans;
    }

    cout << ans << endl;
}
