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
void DFS(int V)
{
	visited[V] = 1;
	for (int i = 0; i < D[V].size(); ++i) {
		if (!visited[D[V][i]])
			DFS(D[V][i]);
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
			DFS(i);
			ct++;
		}
	}
	printf("%d\n", ct);
}
