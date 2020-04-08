/*
* https://www.acmicpc.net/problem/1874
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<char> vec;
    stack<int> s;
    int n = 1, N, num;

    cin >> N;
    while (N--)
    {
        cin >> num;

        while (n <= num)
        {
            s.push(n++);
            vec.push_back('+');
        }

        if (s.top() == num)
        {
            s.pop();
            vec.push_back('-');
        }
    }
    if (!s.empty()) cout << "NO";
    else
        for (auto c : vec)
            cout << c << '\n';
}
