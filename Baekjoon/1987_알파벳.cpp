/*
* https://www.acmicpc.net/problem/1987
*/
#include <bits/stdc++.h>
using namespace std;

int R, C, N;
bool c[26] = {false,};
bool visit[21][21] = {false, };
int m[21][21];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void dfs(int y, int x, int n)
{
	for (int k = 0; k < 4; ++k) {
		int newY = y + dy[k];
		int newX = x + dx[k];
		if (newY >= 0 && newY < R && newX >= 0 && newX < C && !c[m[newY][newX] - 'A'] && !visit[newY][newX]) {
			c[m[newY][newX] - 'A'] = true;
			visit[newY][newX] = true;
			dfs(newY, newX, n + 1);
			c[m[newY][newX] - 'A'] = false;
			visit[newY][newX] = false;
		}
	}

	N = max(N, n);
}

int main()
{
	cin >> R >> C;
	string in;
	for (int i = 0; i < R; ++i) {
		cin >> in;
		for (int j = 0; j < in.size(); ++j)
			m[i][j] = in[j];
	}

	c[m[0][0] - 'A'] = true;
	visit[0][0] = true;
	dfs(0, 0, 1);

	cout << N << endl;
}
