/*
* https://programmers.co.kr/learn/courses/30/lessons/43163
*/
#include <bits/stdc++.h>
using namespace std;

int duplicate(const string& s1, const string& s2)
{
    int ct = 0;
    for (int i = 0; i < s1.size(); ++i)
   		ct += s1[i] == s2[i] ? 1 : 0;
    return ct;
}

int solution(string begin, string target, vector<string> words) {
    stack<pair<string, int> > s;
    vector<bool> check(words.size(), false);
    int dup;
    s.push(make_pair(begin, 0));
    
    while (!s.empty())
    {
        string b = s.top().first;
        int cur = s.top().second;
        s.pop();
        dup = duplicate(b, target);
        
        if (b == target)
            return cur;
        
        for (int i = 0; i < words.size(); ++i) {
            int wdup = duplicate(target, words[i]);
            if (!check[i] && duplicate(b, words[i]) == b.size() - 1 && (wdup == cur + 1 || wdup == cur)) { 
                s.push(make_pair(words[i], cur + 1));
                check[i] = true;
            }
        }
    }
    
    return 0;
}
