/*
* https://www.acmicpc.net/problem/1138
*/
#include <bits/stdc++.h>
using namespace std;

int a[11], N;
int main()
{
    cin >> N;

    for (int i = 1; i <= N; ++i) {
        int input;
        cin >> input;

        for (int j = 0; j < N; ++j) {
            if (input == 0 && a[j] == 0) {
                a[j] = i;
                break;
            }
            else if (a[j] == 0)
                input--;
        }
    }

    for (int i = 0; i < N; ++i)
        cout << a[i] << " ";
}
