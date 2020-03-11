/*
* https://www.acmicpc.net/problem/1541
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    
    bool minus = false;
    string temp = "";
    int tot = 0;

    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == '-' || s[i] == '+')
        {
            if (minus)
                tot -= stoi(temp);
            else
                tot += stoi(temp);

            if (s[i] == '-')
                minus = true;
            
            temp = "";
            continue;
        }

        temp += s[i]; 
    }
    if (minus) tot -= stoi(temp);
    else tot += stoi(temp);

    cout << tot << endl;
}
