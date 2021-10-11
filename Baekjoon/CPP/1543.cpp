/*
* https://www.acmicpc.net/problem/1543
*/
#include <bits/stdc++.h>
using namespace std;
typedef string::iterator iter;

int main()
{
    iter it, temp;
    string str, ans;
    int ct = 0, len = 0, pos;

    getline(cin, str);
    getline(cin, ans);

    while (true) {
        pos = str.find(ans, 0);

        if (pos == string::npos) break;

        str = str.substr(pos + ans.size());

        ct++;
    }

    cout << ct;
}
