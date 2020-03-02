#include <bits/stdc++.h>
using namespace std;

int n, s, k, t;
int main()
{
	for (cin >> t; t > 0; --t) {
		scanf("%d %d %d", &n, &s, &k);
		int a[k];
		for (int i = 0; i < k; ++i) {
			scanf("%d", &a[i]);
		}

		sort(a, a + k);

		for (int i = 0; i <= k; ++i) {
			if ((s - i >= 1 && !binary_search(a, a + k, s - i)) || 
				(s + i <= n && !binary_search(a, a + k, s + i))) {
				 printf("%d\n", i);
				 break;
			}
		}
	}
}
