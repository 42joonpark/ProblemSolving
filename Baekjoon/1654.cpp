/*
* https://www.acmicpc.net/problem/1654
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int K, N, st, ed, max_length = 0;
    vector<int> lines;

    cin >> K >> N;
    lines.resize(K);

    for (int i = 0; i < K; ++i)
        cin >> lines[i];

    st = 1;
    ed = 1LL << 31;

    while (st < ed) {
        long long int mid = (st + ed) / 2;
        long long int sum = 0;

        for (int i = 0; i < K; ++i)
            if (lines[i] >= mid)
                sum += lines[i] / mid;

        if (sum >= N) {
            max_length = max(max_length, mid);
            st = mid + 1;
        }
        else ed = mid;
    } 
    cout << max_length;
}
