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

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int N, M, MAX;
int temp[10][10], room[10][10];
int visit[10][10];

void virus()
{
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			temp[i][j] = room[i][j];

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (temp[i][j] == 2) {
				queue<pair<int, int> > q;
				q.push(make_pair(i, j));

				while (!q.empty()) {
					int newX = q.front().first;
					int newY = q.front().second;
					q.pop();

					for (int p = 0; p < 4; ++p) {
						int X = newX + dx[p];
						int Y = newY + dy[p];
						if (X >= 0 && Y >= 0 && X < N && Y < M && temp[X][Y] == 0) {
							temp[X][Y] = 2;
							q.push(make_pair(X, Y));
						}
					}
				}
			}
		}
	}

	int res = 0;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			if (temp[i][j] == 0) ++res;

	MAX = max(MAX, res);
}

void wall(int ct)
{
	if (ct == 3) {
		virus();
		return;
	}

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j) {
			if (room[i][j] == 0) {
				room[i][j] = 1;
				wall(ct + 1);
				room[i][j] = 0;
			}
		}
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j)
			scanf("%d", &room[i][j]);
	}

	wall(0);

	cout << MAX << endl;
}
