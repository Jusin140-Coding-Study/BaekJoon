#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

int N, M, R;
vector<vector<int>> graph;
vector<int> visited;

void BFS(int _start);

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> R;


	graph.resize(N + 1);
	visited.resize(N + 1);
	
	for (int i = 0; i < M; ++i) {

		int s, e;
		cin >> s >> e;
		
		graph[s].push_back(e);
		graph[e].push_back(s);

	}


	for (int i = 1; i <= N; ++i) {

		sort(graph[i].begin(), graph[i].end(), greater<int>());

	}


	BFS(R);

	for (int i = 1; i <= N; ++i) {

		cout << visited[i] << '\n';

	}


	return 0;
}


void BFS(int _start) {

	queue<int> q;
	q.push(_start);

	int count = 1;
	visited[_start] = count;

	while (!q.empty()) {

		int current = q.front();
		q.pop();
		
		for (int i = 0; i < (int)graph[current].size(); ++i) {

			int next = graph[current][i];
			
			if (0 == visited[next]) {

				++count;
				visited[next] = count;
				q.push(next);

			}

		}

	}

}
