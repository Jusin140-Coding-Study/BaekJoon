#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

static vector<vector<int>> Graph;
static vector<bool> Visited;

void DFS(int iIndex);
void BFS(int iIndex);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, V;
	cin >> N >> M >> V;

	Graph = vector<vector<int>>(N + 1, vector<int>());
	Visited = vector<bool>(N + 1, false);

	for (int i = 0; i < M; ++i)
	{
		int s, e;
		cin >> s >> e;

		Graph[s].push_back(e);
		Graph[e].push_back(s);
	}

	for (auto& nodes : Graph)
		sort(nodes.begin(), nodes.end());

	DFS(V); cout << "\n";

	fill(Visited.begin(), Visited.end(), false);
	BFS(V);

	return 0;
}

void DFS(int iIndex)
{
	Visited[iIndex] = true;
	cout << iIndex << " ";

	for (const auto& V : Graph[iIndex])
	{
		if (!Visited[V]) DFS(V);
	}
}

void BFS(int iIndex)
{
	queue<int> Q;
	Q.push(iIndex);
	Visited[iIndex] = true;

	while (!Q.empty())
	{
		int iCurNode = Q.front();
		Q.pop();
		cout << iCurNode << " ";

		for (const auto& V : Graph[iCurNode])
		{
			if (!Visited[V])
			{
				Q.push(V);
				Visited[V] = true;
			}
		}
	}
}