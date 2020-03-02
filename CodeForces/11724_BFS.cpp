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

int visited[1001];
vector<int> D[1001];
void BFS(int vertex)
{
	queue<int> q;
	q.push(vertex);
	visited[vertex] = 1;

	while (!q.empty()) {
		int v = q.front();
		q.pop();

		for (int i = 0; i < D[v].size(); ++i) {
			int next = D[v][i];
			if (!visited[next]) {
				visited[next] = 1;
				q.push(next);
			}
		}
	}
}

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; ++i) {
		int s, e;
		scanf("%d %d", &s, &e);
		D[s].push_back(e);
		D[e].push_back(s);
	}

	int ct = 0;
	for (int i = 1; i <= N; ++i) {
		if (!visited[i]) {
			BFS(i);
			ct++;
		}
	}
	printf("%d\n", ct);
}
