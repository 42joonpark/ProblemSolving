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

int t, n, k, p;
int a[100001];

int main()
{
	for (cin >> t; t > 0; --t) {
		cin >> n >> p >> k;

		for (int i = 0; i < n; ++i)
			scanf("%d", &a[i]);

		k = 2;
		int curMax = 0, count = 0;
		for (int i = 0; i < n; ++i) {
			if (a[i] > curMax) {
				if (k == 0) break;
				if (a[i] <= p) {
					k = 2;
					curMax = a[i];
					p -= a[i];
				}
				else break;
			} else {
				if (k < 0) break;
				--k;
			}
			count++;
		}
		printf("%d\n", count);
	}
}
