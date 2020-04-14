/*
* https://codeforces.com/problemset/problem/1324/C
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    
    while (t--) {
        string s;
        int m_max = 0;
        int dis = 1;
        cin >> s;
        
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == 'R') {
                m_max = max(m_max, dis);
                dis = 1;
            } else {
                ++dis;
            }
        }
        
        m_max = max(m_max, dis);
        
        cout << m_max << endl;
    }
}
