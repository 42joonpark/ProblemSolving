/*
* https://www.acmicpc.net/problem/1439
*/
#include <bits/stdc++.h>
using namespace std;

int one, zero;
int main()
{
    string str;

    cin >> str;
    
    str[0] == '0' ? zero++ : one++;
    for (int i = 1; i < str.size(); ++i) {
        if (str[i] == '0' && str[i - 1] == '1') 
            zero++;
        else if (str[i] == '1' && str[i - 1] == '0')
            one++;
    }

    cout << min(one, zero);
}
