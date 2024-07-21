#include <iostream>
#include <vector>
using namespace std;

static vector<vector<int>> Graph;
static vector<int> Check;
static vector<bool> Visited;
static bool IsEven;
void DFS(int node);

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

		Graph.resize(V + 1);
		Visited.resize(V + 1);
		Check.resize(V + 1);
		IsEven = true;

		for(int j = 0; j < E; ++j)
		{
			int u = 0; int v = 0;
			cin >> u >> v;

			Graph[u].push_back(v);
			Graph[v].push_back(u);
		}

		// 주어진 그래프가 하나로 연결된다는 보장이 없으므로 모든 노드에서 수행
		for (int j = 1; j <= V; ++j)
		{
			if (IsEven)
				DFS(j);
			else
				break;
		}

		if (IsEven)
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";

		for (int j = 0; j <= V; ++j)
		{
			Graph.clear();
			Visited[j] = false;
			Check[j] = 0;
		}
	}
}

void DFS(int node)
{
	Visited[node] = true;

	for (auto index : Graph[node])
	{
		if (!Visited[index])
		{
			Check[index] = (Check[node] + 1) % 2;
			DFS(index);
		}
		else if(Check[node] == Check[index])
		{
			IsEven = false;
		}
	}
}