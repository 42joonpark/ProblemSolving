/*
* https://www.acmicpc.net/problem/1475
*/
#include <bits/stdc++.h>
using namespace std;

int nums[9], m, c;
int main()
{
    string line;
    cin >> line;

    for (int i = 0; i < line.size(); ++i)
    {
        if (line[i] == '9')
            nums[6]++;
        else nums[line[i] - '0']++;
    }

    for (int i = 0; i < 9; ++i)
    {
        if (i == 6) 
            c = nums[i] % 2 == 0 ? nums[i] / 2 : nums[i] / 2 + 1;
        else c = nums[i];

        m = max(m, c);
    }

    cout << m;
}
