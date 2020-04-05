/*
* https://www.acmicpc.net/problem/5622
*/
#include <bits/stdc++.h>
using namespace std;

int num[10] = {0, 0, 3, 6, 9, 12, 15, 19, 22, 26};
int main()
{
    string line;
    cin >> line;

    int sum = 0, cur = 0;
    for (int i = 0; i < line.size(); ++i)
    {
        int c = tolower(line[i]) - 'a' + 1;
        cur = 0;
        for (int j = 2; j < 10; ++j)
        {
            if (c <= num[j])
            {
                cur = j;
                break;
            }
        }
        sum += cur;
    }

    cout << sum + line.size();
}
