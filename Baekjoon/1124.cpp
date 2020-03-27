/*
* https://www.acmicpc.net/problem/1124
*/
#include <bits/stdc++.h>
using namespace std;

int A, B;
int nums[100001];

bool sosu(int num)
{
    if (num == 1) return false;
    for (int i = 2; i <= sqrt(num); ++i) 
        if (num % i == 0) return false;

    return true;
}

void initialize()
{
    nums[1] = 1;
    for (int i = 2; i <= 100000; ++i) {
        if (sosu(i))
            nums[i] = 1;
        else if (i % 2 == 0)
            nums[i] = nums[i / 2] + 1;
        else {
            for (int j = 3; j <= i; j += 2) {
                if (i % j == 0) {
                    nums[i] = nums[i / j] + 1;
                    break;
                }
            }
        }
    }
}

int main()
{
    int ct = 0;
    cin >> A >> B;

    initialize();

    for (int i = A; i <= B; ++i)
    {
        if (sosu(nums[i]))
            ct++;
    }

    cout << ct << endl;
}
