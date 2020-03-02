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

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int paper[101][101];
int N, M, K;

int FIND(int y, int x)
{
	queue<pair<int, int> > q;
	q.push(make_pair(y, x));
	paper[y][x] = 1;
	int ct = 1;

	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int newX = x + dx[i];
			int newY = y + dy[i];
			if (newX >= 0 && newY >= 0 && newX < M && newY < N) {
				if (paper[newY][newX] == 0) {
					paper[newY][newX] = 1;
					ct++;
					q.push(make_pair(newY, newX));
				}
			}
		}
	}
	return ct;
}

int main()
{
	scanf("%d %d %d", &M, &N, &K);

	for (int i = 0; i < K; ++i) {
		int bx, by, tx, ty;
		scanf("%d %d %d %d", &ty, &tx, &by, &bx);

		for (int Y = ty; Y < by; ++Y)
			for (int X = tx; X < bx; ++X)
				paper[Y][X] = 1;
	}

	int MAX = 0;
	vector<int> res;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j) {
			if (paper[i][j] == 0) {
				MAX++;
				res.push_back(FIND(i,j));
			}
		}

	cout << MAX << endl;
	sort(res.begin(), res.end());
	for (int i = 0; i < res.size(); ++i)
		cout << res[i] << " ";
	cout << endl;
}
