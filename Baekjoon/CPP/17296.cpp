/*
* https://www.acmicpc.net/problem/17296
*/
#include <bits/stdc++.h>
using namespace std;

int N, sum;
float input;
bool pressed = false;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> input;
        if (static_cast<int>(input) < input)
        {
            if (!pressed) sum += 1;
            sum += input;
        }
        else if (input == 0)
        {
            continue;
        }
        else
        {
            sum += input;
        }
        pressed = true;
    }
    cout << sum;
}
