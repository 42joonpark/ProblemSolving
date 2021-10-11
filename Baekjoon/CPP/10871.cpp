/*
* https://www.acmicpc.net/problem/10871
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N, X, i;
	cin >> N >> X;
	while (N--) {
		cin >> i;
		if (i < X) cout << i << " ";
	}
}
