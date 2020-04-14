/*
* https://codeforces.com/problemset/problem/1334/B
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int t, n, x;
int main()
{
    cin >> t;
    while (t--) {
        int ans = 0;
        ll sum = 0;
        vector<int> rest;

        cin >> n >> x;
        for (int i = 0; i < n; ++i) {
            int input;
            cin >> input;
            if (input >= x) {
                ans++;
                sum += (input - x);
            }
            else {
                rest.push_back(input);
            }
        }

        sort(rest.begin(), rest.end(), greater<int>());

        for (int k = 0; k < rest.size(); ++k) {
           if (sum + rest[k] < x) break;

            sum -= (x - rest[k]);

            ans++;
        }

        cout << ans << endl;
    }
}
