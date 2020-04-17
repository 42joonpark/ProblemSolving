/*
* https://www.acmicpc.net/problem/10816
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> vec;
    int N, M;

    cin >> N;
    vec.resize(N);

    for (int i = 0; i < N; ++i)
        scanf("%d", &vec[i]);

    sort(vec.begin(), vec.end());

    cin >> M;
    for (int i = 0; i < M; ++i) {
        int val, ct = 0;

        scanf("%d", &val);

        vector<int>::iterator it1, it2;

        it1 = lower_bound(vec.begin(), vec.end(), val);
        it2 = upper_bound(vec.begin(), vec.end(), val);

        printf("%d ", it2 - it1);
    }
}
