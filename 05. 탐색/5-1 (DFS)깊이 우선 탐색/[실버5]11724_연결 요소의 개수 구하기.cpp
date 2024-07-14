#include <iostream>
#include <vector>
using namespace std;

void DFS(int index, vector<vector<int>>& nodes, vector<bool>& visited);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;
	int M = 0;
	int Result = 0;
	cin >> N >> M;

	// 행은 노드의 개수만큼, 열은 가변적이므로 0으로 초기화
	vector<vector<int>> Nodes(N + 1, vector<int>(0, 0));

	// 인접 리스트 구현
	for (int i = 0; i < M; ++i)
	{
		int u = 0;
		int v = 0;
		cin >> u >> v;

		Nodes[u].push_back(v);
		Nodes[v].push_back(u);
	}

	// 방문 배열 초기화
	vector<bool> Visited(N + 1, false);

	for (int i = 1; i <= N; ++i)
	{
		if (!Visited[i])
		{
			Result++;
			DFS(i, Nodes, Visited);
		}
	}

	cout << Result;
}

void DFS(int index, vector<vector<int>>& nodes, vector<bool>& visited)
{
	// 시작 인덱스 방문 완료
	visited[index] = true;

	for (int i = 0; i < nodes[index].size(); ++i)
	{
		if (!visited[nodes[index][i]])
			DFS(nodes[index][i], nodes, visited);
	}
}