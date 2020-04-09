/*
* https://www.acmicpc.net/problem/1182
*/
#include<bits/stdc++.h>
using namespace std;

int N, S, ct;
int a[21];
void func(int sum, int idx)
{
    if (idx >= N) return;
    int t = sum + a[idx];
    if (t == S) ct++;
    
    func(sum + a[idx], idx + 1);
    func(sum, idx + 1);
}
int main()
{
    cin >> N >> S;
    for (int i = 0; i < N; ++i)
           cin >> a[i];
    
    func(0, 0);
    cout << ct;
}
