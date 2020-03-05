#include <bits/stdc++.h>
using namespace std;

int solution(string s) {
    stack<int> t;
    
    for (int i = 0; i < s.size(); ++i) {
        if (t.empty()) t.push(i);
        else {
            int b = t.top();
            if (s[b] == s[i]) t.pop();
            else t.push(i);
        }
    }
    return t.empty() ? 1 : 0;
}
