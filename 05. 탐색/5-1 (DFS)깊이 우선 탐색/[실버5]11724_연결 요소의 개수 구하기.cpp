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

	// ���� ����� ������ŭ, ���� �������̹Ƿ� 0���� �ʱ�ȭ
	vector<vector<int>> Nodes(N + 1, vector<int>(0, 0));

	// ���� ����Ʈ ����
	for (int i = 0; i < M; ++i)
	{
		int u = 0;
		int v = 0;
		cin >> u >> v;

		Nodes[u].push_back(v);
		Nodes[v].push_back(u);
	}

	// �湮 �迭 �ʱ�ȭ
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
	// ���� �ε��� �湮 �Ϸ�
	visited[index] = true;

	for (int i = 0; i < nodes[index].size(); ++i)
	{
		if (!visited[nodes[index][i]])
			DFS(nodes[index][i], nodes, visited);
	}
}