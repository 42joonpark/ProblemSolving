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
int n, t;

int main()
{
	for (cin >> t; t > 0; --t) {
		cin >> n;	

		vector<int> temp(n);
		map<int, int> m;
		int ct = 0;
		for (int i = 0; i < n; ++i)
			cin >> temp[i];
		
		sort(temp.begin(), temp.end());

		for (int i = 0; i < n; ++i) {
			int a = temp[i];
			while (a % 2 == 0 && m[a] == 0) {
				m[a]++;
				ct++;
				a /= 2;
			}
		}

		cout << ct << endl;
	}
}
