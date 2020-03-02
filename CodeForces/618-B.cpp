#include <bits/stdc++.h>
using namespace std;

int t, n;
int main()
{
	for (cin >> t; t > 0; --t) {
		vector<int> temp;

		cin >> n;
		temp.resize(2 * n);
		for (int i = 0; i < 2 * n; ++i) 
			cin >> temp[i];

		sort(temp.begin(), temp.end());

		int mid = n;
		cout << temp[mid] - temp[mid - 1] << endl;
	}
}
