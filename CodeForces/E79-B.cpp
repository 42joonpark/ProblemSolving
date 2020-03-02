#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <list>
#include <vector>
#include <queue>
#include <stack>
#include <map>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int t, n, s, idx, MAX, a[100001], sum;
int main()
{
	for (cin >> t; t > 0; --t) {
		cin >> n >> s;
		for (int i = 1; i <= n; ++i)
			scanf("%d", &a[i]);
		sum = 0;
		idx = 0;
		MAX = 0;
	
		for (int i = 1; i <= n; ++i) {
			sum += a[i];
			if (MAX < a[i]) {
				MAX = a[i];
				idx = i;
			}

			if (sum > s) {
				break;
			}
		}

		if (sum > s) cout << idx << endl;
		else cout << 0 << endl;
	}
}
