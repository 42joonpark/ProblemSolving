/*
* https://www.acmicpc.net/problem/2871
*/
#include <bits/stdc++.h>
using namespace std;

string str, sang = "", hone = "";
int tot, N, a[26], vis[100001];
map<char, stack<int> > R;

int main()
{
    cin >> N >> str;

    for (int i = 0; i < N; ++i) {
        a[str[i] - 'a']++;
        R[str[i]].push(i);
        vis[i] = false;
    }

    int it = str.size();
    while (tot < N) {
        --it;
        while (vis[it] || a[str[it] - 'a'] <= 0)
            --it;
        
        sang += str[it];
        a[str[it] - 'a']--;
        R[str[it]].pop();
        vis[it] = true;
        tot++;

        char cur;
        for (int i = 0; i < 26; ++i)
            if (a[i] > 0)
            {
                cur = ('a' + i);
                a[i]--;
                tot++;
                break;
            }
        hone += cur;
        int pos = R[cur].top();
        R[cur].pop();
        vis[pos] = true;
    }

    if (sang <= hone) {
        cout << "NE\n";
    }
    else {
        cout << "DA\n";
    }
    cout << hone;
}
