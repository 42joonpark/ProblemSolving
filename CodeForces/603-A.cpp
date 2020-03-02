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
int t, c[3];

int main()
{
	for (cin >> t; t > 0; --t) {
		cin >> c[0] >> c[1] >> c[2];

		int z = 0;
		int ct = 0;

		if (c[0] != 0) z++;
		if (c[1] != 0) z++;
		if (c[2] != 0) z++;
		while (z > 1) {
			sort(c, c + 3);
			c[1]--;
			c[2]--;
			ct++;

			z = 0;
			if (c[0] != 0) z++;
			if (c[1] != 0) z++;
			if (c[2] != 0) z++;
		}
		cout << ct << endl;
	}
}
