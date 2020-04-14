/*
* https://codeforces.com/problemset/problem/1304/B
*/
#include <bits/stdc++.h>
using namespace std;

bool is_palindrome(string& s1, string& s2)
{
    return equal(s1.begin(), s1.end(), s2.rbegin());
}

int main()
{
    vector<string> F, words;
    string palin;
    stack<string> B;
    vector<bool> check;
    int n, m;

    cin >> n >> m;
    check.resize(n);

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        words.push_back(s); 
    }

    sort(words.begin(), words.end());

    for (int i = 0; i < n; ++i) {
        if (check[i]) continue;
        if (is_palindrome(words[i], words[i]))
            palin = words[i];
        check[i] = true;
        for(int j = i + 1; j < n; ++j) {
            if (!check[j] && is_palindrome(words[i], words[j])) {
                F.push_back(words[i]);
                B.push(words[j]);
                check[j] = false;
            }

        }
    }
    
    string ans = "";
    for (auto a : F)
        ans += a;
    ans += palin;
    while (!B.empty()) {
        ans += B.top();
        B.pop();
    }

    cout << ans.size() << endl;
    if (ans.size()) cout << ans;
}
