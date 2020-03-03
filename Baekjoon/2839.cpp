#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N, ct = 0;
	cin >> N;

	while (N >= 3) {
		if (N % 3 != 0 && N % 5 != 0)
			N -= 5;
		else if (N % 3 == 0 && N % 5 == 0)
			N -= 5;
		else if (N % 3 == 0 && N % 5 != 0)
			N -= 3;
		else if (N % 5 == 0 && N % 3 != 0)
			N -= 5;
		ct++;
	}

	if (N != 0) ct = -1;
	cout << ct << endl;
}
