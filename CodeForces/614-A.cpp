#include <bits/stdc++.h>
using namespace std;

int t, n, s, k, up = 1e9, down = 1e9;
vector<int> vec;

int main()
{
	for (cin >> t; t > 0; --t) {
		vec.clear();
		up = 2e9;
		down = 2e9;
		scanf("%d %d %d", &n, &s, &k);

		for (int i = 0; i < k; ++i) {
			int a;
			scanf("%d", &a);
			vec.push_back(a);
		}

		for (int i = s; i <= n; ++i) {
			bool f = false;
			vector<int>::iterator j;
			for (j = vec.begin(); j != vec.end(); ++j) {
				if (*j == i) {
					f = true;
					break;
				}
			}

			if (!f) {
				up = i;
				break;
			}
		}

		for (int i = s; i > 0; --i) {
			bool f = false;
			vector<int>::iterator j;
			for (j = vec.begin(); j != vec.end(); ++j) {
				if (*j == i){
					f = true;
					break;
				}
			}

			if (!f) {
				down = i;
				break;
			}
		}

		int res;

		res = abs(up -s ) > abs(s - down) ? abs(s - down) : abs(up - s);

		printf("%d\n",res);
	}
}
