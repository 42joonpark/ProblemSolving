#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

bool visited[1001];
vector<int> R[1001];
void DFS(int vertex)
{
	printf("%d ", vertex);	
	visited[vertex] = 1;


	for (int i = 0; i < R[vertex].size(); ++i) {
		int next = R[vertex][i];
		if (!visited[next])
			DFS(next);
	}
}

void BFS(int vertex)
{
	queue<int> s;
	s.push(vertex);

	while (!s.empty()) {
		int v = s.front();
		s.pop();
		printf("%d ", v);
		visited[v] = 1;
		
		for (int i = 0; i < R[v].size(); ++i) {
			int next = R[v][i];
			if (!visited[next]) {
				visited[next] = 1;
				s.push(next);
			}
		}
	}
}

int main()
{
	int N, M, V;
	cin >> N >> M >> V;

	for (int i = 0; i < M; ++i) {
		int s, e;
		scanf("%d %d", &s, &e);
		R[s].push_back(e);
		R[e].push_back(s);
	}

	for (int i = 1; i <= N; ++i) {
		sort(R[i].begin(), R[i].end());	
	}

	DFS(V);

	cout << endl;

	for (int i = 0; i < 1001; ++i)
		visited[i] = 0;

	BFS(V);
}
