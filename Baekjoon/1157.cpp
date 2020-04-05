/*
* https://www.acmicpc.net/problem/1157
*/
#include <bits/stdc++.h>
using namespace std;

int alphabet[26], m, ct, pos;
int main()
{
    string line;
    cin >> line;

    for (int i = 0; i < line.size(); ++i)
        alphabet[tolower(line[i]) - 'a']++;

    for (int i = 0; i < 26; ++i)
    {
        if (alphabet[i] > m)
        {
            m = alphabet[i];
            pos = i;
            ct = 0;
        }
        if (alphabet[i] == m)
            ct++;
    }

    if (ct > 1)
        cout << '?';
    else
        cout << (char)(pos + 'A');
}
