/*
* https://www.acmicpc.net/problem/2231
*/
#include <bits/stdc++.h>
using namespace std;

int getCt(int num)
{
    int ct = 0;
    while (num > 0) {
        ct++;
        num /= 10;
    }
    return ct;
}

int getSum(int num, int ct)
{
    int start = num - (9 * ct);
    start = start < 0 ? 0 : start;
    for (int i = start; i <= num; ++i)
    {
        int temp = i;
        int sum = i;
        while (temp > 0) {
            sum += (temp % 10);
            temp /= 10;
        }
        if (sum == num)
           return i;
    }
    return 0;
}

int main()
{
    int N;
    cin >> N;
    cout << getSum(N, getCt(N));
}
