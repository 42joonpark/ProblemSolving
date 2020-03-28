/*
* https://www.acmicpc.net/problem/5052
*/
#include <bits/stdc++.h>
using namespace std;

bool phone_book(vector<string>& phone) {
    for (int i = 1; i < phone.size(); ++i) {
        if (phone[i].size() > phone[i - 1].size()) {
            string temp = phone[i].substr(0, phone[i - 1].size());
            if (phone[i - 1] == temp) {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n;
    for (cin >> t; t > 0; --t) {
        vector<string> phone;

        cin >> n;
        phone.resize(n);

        for (int i = 0; i < n; ++i)
            cin >> phone[i];

        sort(phone.begin(), phone.end());

        if (phone_book(phone)) cout << "YES\n";
        else cout << "NO\n";
    }
}
