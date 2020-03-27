/*
* https://www.acmicpc.net/problem/2529
*/
#include <bits/stdc++.h>
using namespace std;

vector<string> ans;
string MIN = "0123456789";
string input;
int k;

bool func(char a, char b, char c) {
    if (b == '>')
        return a - '0' > c - '0';
    else
        return a - '0' < c - '0';
}

void dfs(string str, string& chars, vector<bool>& check, int idx) {
    if (idx == k) {
        ans.push_back(str);
        return;
    }

    for (int i = 0; i < 10; ++i) {
        int cur = chars[i] - '0';
        if (!check[cur]) {
            if (func(str[str.size() - 1], input[idx], chars[i])) {
                check[cur] = true;
                dfs(str + chars[i], chars, check, idx + 1);
                check[cur] = false;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<bool> check(10, false);

    cin >> k;
    input.resize(k);
    for (int i = 0; i < k; ++i) {
        cin >> input[i];
    }

    string res = "";
    for (int i = 0; i < 10; ++i) {
        check[MIN[i] - '0'] = true;
        dfs(res + MIN[i], MIN, check, 0);
        check[MIN[i] - '0'] = false;
    }

    cout << ans[ans.size() - 1] << '\n' << ans[0] << '\n';
}
