/*
* https://www.acmicpc.net/problem/2805
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> trees;
    int N, M, st, ed, ans = 0;

    cin >> N >> M;
    trees.resize(N);

    for (int i = 0; i < N; ++i)
        scanf("%d", &trees[i]);

    st = 0;
    ed = 2000000001;

    while (st < ed) {
        int mid = (st + ed) / 2;
        long long int sum = 0;

        for (int i = 0; i < trees.size(); ++i) 
            if (trees[i] > mid)
                sum += (trees[i] - mid);

        if (sum >= M) {
            st = mid + 1;
            ans = max(ans, mid);
        }
        else ed = mid;
    }
    cout << ans ;
}
