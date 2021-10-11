/*
* https://www.acmicpc.net/problem/2309
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> a(9);
int sum;
int main()
{
    bool found = false;
    for (int i = 0; i < 9; ++i)
    {
        cin >> a[i];
        sum += a[i];
    }
    
    for (int i = 0; i < 9; ++i)
    {
        int  temp = sum;
        int n = a[i];
        temp -= n;
        a[i] = 0;
        for (int j = 0; j < 9; ++j)
        {
            int m = a[j];
            if (i == j) continue;
            temp -= m;
            if (temp == 100)
            {
                found = true;
                a[j] = 0;
                break;
            }
            temp += m;
        }
        if (found) break;
        a[i] = n;
    }
    
    sort(a.begin(), a.end());
    for (int i = 2; i < 9; ++i)
            cout << a[i] << endl;
}
