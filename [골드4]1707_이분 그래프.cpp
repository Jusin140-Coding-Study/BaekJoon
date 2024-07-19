#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int, int> Node;
vector<vector<Node>> Graph;
vector<bool> Visited;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int K = 0;
	cin >> K;
	
	for (int i = 0; i < K; ++i)
	{
		int V = 0; int E = 0;
		cin >> V >> E;

		Visited = vector<bool>(V, false);

		Graph.clear();
		// �׷� A, B����
		Graph = vector<vector<Node>>(V + 1, vector<Node>());
		for (int j = 0; j < E; ++j)
		{
			int u = 0; int v = 0;
			cin >> u >> v;

			Graph[u].push_back({v, A});
			Graph[v].push_back(u);
		}

		// BFS
		BFS(Graph[1].front());
	}

	return 0;
}

bool BFS(int index)
{
	// �湮�� ��� �����ϰ�, ����� ���� �̵����� ��,
	// �� ��尡 ���� ����� �׷�� �ٸ��ٸ� ����ؼ� Ž��.
	// �׷��� �ʴٸ� false�� ��ȯ.
	// ť�� �� �� ���� Ž���� ��� ��ٸ�, true ��ȯ

	queue<int> Q;
	Q.push(index);
	Visited[index] = true;
	
	while (!Q.empty())
	{
		int curNode = Q.front();
		Q.pop();

		for (int i = 0; i < Graph[index].size(); ++i)
		{
			if (!Visited[Graph[index][i]])
			{
				Visited[Graph[index][i]] = true;
				Q.push(Graph[index][i]);
			}
		}
	}
}