/*
* https://www.acmicpc.net/problem/2869
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A, B, V, T;
    cin >> A >> B >> V;

    T = (V - A) / (A - B) + 1;
    if ((V - A) % (A - B) == 0)
        cout << T << endl; 
    else
        cout << T + 1 << endl;
}
