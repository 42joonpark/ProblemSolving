// https://www.acmicpc.net/problem/1759

#include <bits/stdc++.h>
using namespace std;

int C, L;
string A;

void check(string& str)
{
    int ct = 0;
    for_each(str.begin(), str.end(), [&ct](const char& c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            ct++;
    });
    if (ct >= 1 && str.size() - ct >= 2)
        cout << str << endl;
}

void recursive(string str, int pos, int t)
{
    if (str.size() == L) {
        check(str);
        return;
    }

    for (int i = pos ; i <= C - t; ++i) {
        recursive(str + A[i], i + 1, t - 1);
    }
}

int main()
{
    cin >> L >> C;

    A.reserve(C);

    char c;
    for (int i = 0; i < C; ++i) {
        cin >> c;
        A += c;
    }

    sort(A.begin(), A.end());

    recursive(""s, 0, L);
}
