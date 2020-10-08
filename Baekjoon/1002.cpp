// https://www.acmicpc.net/problem/1002

#include <bits/stdc++.h>
using namespace std;

void func(int x1, int y1, int r1, int x2, int y2, int r2)
{
    double D = sqrt(pow(x1 - x2, 2.0) + pow(y1 - y2, 2.0));
    if (r1 < r2) {
        int t = r1;
        r1 = r2;
        r2 = t;
    }

    if (D <= r1) {
        if (x1 == x2 && y1 == y2 && r1 == r2) cout << -1 << endl;
        else if (D + r2 == r1) cout << 1 << endl;
        else if (D + r2 < r1) cout << 0 << endl;
        else if (D + r2 > r1) cout << 2 << endl;
    } else {
        if (D > r1 + r2) cout << 0 << endl;
        else if (D == r1 + r2) cout << 1 << endl;
        else if (D < r1 + r2) cout << 2 << endl;
    }
}

int main()
{
    int T;
    cin >> T;

    while (T--) {
        int x1, x2, y1, y2, r1, r2;

        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        func(x1, y1, r1, x2, y2, r2);
    }
}
