/*
* https://www.acmicpc.net/problem/10815
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M, st, ed;
    vector<int> cards;

    cin >> N;
    cards.resize(N);
    for (int i = 0; i < N; ++i)
        cin >> cards[i];

    sort(cards.begin(), cards.end());

    cin >> M;
    for (int i = 0; i < M; ++i) {
        int input;
        bool found = false;

        st = 0;
        ed = cards.size();
        
        scanf("%d", &input);
        while (st < ed) {
            int mid = (st + ed) / 2;

            if (cards[mid] == input) {
                found = true;
                break;
            }
            else if (input < cards[mid]) ed = mid;
            else st = mid + 1;
        }

        if (found) cout << 1 << " ";
        else cout << 0 << " ";
    }
}
