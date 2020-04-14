/*
* https://www.acmicpc.net/problem/9576
*/
#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int>& p1, pair<int, int>& p2)
{
    return p1.second < p2.second;
}

int main()
{
    int N, M, a, b, t;

    cin >>  t;
    while (t--) {
        vector<pair<int, int> > vec;
        vector<bool> choose;

        cin >> N >> M;
        vec.resize(M);
        choose.resize(N);
        for (int i = 0; i < M; ++i) {
            cin >> a >> b;

            vec[i].first = a;
            vec[i].second = b;
        }

        sort(vec.begin(), vec.end(), compare);

        int ct = 0;
        for (int i = 0; i < M; ++i) {
            for (int j = vec[i].first; j <= vec[i].second; ++j) {
                if (!choose[j]) {
                    choose[j] = true;
                    ct++;
                    break;
                }
            }
        }
        cout << ct << endl;
    }
}
