/*
* https://codeforces.com/problemset/problem/580/A
*/

/////////////////// using stack
/*
#include <bits/stdc++.h>
using namespace std;

int a[100001];
int main()
{
    stack<int> s;
    int N, m_max = 0;

    cin >> N;
    
    for (int i = 0; i < N; ++i)
        cin >> a[i];

    for (int i = 0; i < N; ++i)
    {
        if (!s.empty() && s.top() > a[i])
        {
            m_max = max(m_max, (int)s.size());
            while (!s.empty()) s.pop();        
        }
        s.push(a[i]);
    }        
    m_max = max(m_max, (int)s.size());
    cout << m_max;
}
*/

////////////////// just...
/*
#include <bits/stdc++.h>
using namespace std;

int a[100001];
int main()
{
    int N, ct = 0, ans = 0;

    cin >> N >> a[0];

    ans = ct = 1;
    for (int i = 1; i < N; ++i)
    {
        cin >> a[i];
        
        if (a[i] < a[i - 1])
            ct = 1;
        else 
            ct++;

        ans = max(ans, ct);
    }
    cout << ans;
}
*/
