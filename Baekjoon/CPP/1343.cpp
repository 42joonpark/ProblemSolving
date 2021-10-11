/*
* https://www.acmicpc.net/problem/1343
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;

    cin >> str;

    int idx = 0;
    while (idx < str.size()) {
        if (str[idx] == '.') {
            ++idx;
            continue;
        }

        int ct = 0;
        int temp = idx;
        while (temp < str.size() && str[temp] == 'X') {
            ++temp;
            ++ct;
        }

        if (ct % 2 != 0) {
            cout << -1;
            return 0;
        }

        temp = idx;
        idx += ct ;
        while (ct > 0) {
            if (ct >= 4) {
                str[temp] = 'A';
                str[temp + 1] = 'A';
                str[temp + 2] = 'A';
                str[temp + 3] = 'A';
                ct -= 4;
                temp += 4;
            }
            else if (ct == 2) {
                str[temp] = 'B';
                str[temp + 1] = 'B';
                ct -= 2;
            }
        }
    }

    cout << str;
}
