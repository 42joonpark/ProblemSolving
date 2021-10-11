#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N, d;
	cin >> N;
	d = N / 5;

	while (d >= 0) {
		if ((N - 5 * d) % 3 == 0) {
			cout << d + (N - 5 * d) / 3 << endl;
			return 0;
		}
		--d;
	}
	cout << -1 << endl;
}
