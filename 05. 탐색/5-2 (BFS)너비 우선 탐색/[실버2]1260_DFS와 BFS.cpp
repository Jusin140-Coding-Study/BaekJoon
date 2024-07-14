#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

static vector<vector<int>> Nodes;
static vector<bool> Visited;
static vector<int> Result;
void DFS(int index);
void BFS(int index);
void PrintResult();
static int N;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	N = 0;
	int M = 0;
	int V = 0;
	cin >> N >> M >> V;

	Nodes = vector<vector<int>>(N + 1, vector<int>(0, 0));
	for (int i = 0; i < M; ++i)
	{
		int u = 0;
		int v = 0;
		cin >> u >> v;

		Nodes[u].push_back(v);
		Nodes[v].push_back(u);
	}

	// DFS
	Visited = vector<bool>(N + 1, false);
	Result = vector<int>(0, 0);
	DFS(V);
	PrintResult();

	// BFS
	Visited = vector<bool>(N + 1, false);
	Result = vector<int>(0, 0);
	BFS(V);
	PrintResult();
}

void DFS(int index)
{
	Visited[index] = true;
	Result.push_back(index);

	// 작은 인덱스부터 접근해야 하므로 인접 리스트를 정렬한다.
	sort(Nodes[index].begin(), Nodes[index].end());
	for (int i = 0; i < Nodes[index].size(); ++i)
	{
		if (!Visited[Nodes[index][i]])
			DFS(Nodes[index][i]);
	}
}
void BFS(int index)
{
	queue<int> Q;

	// 첫 노드 방문 체크
	Q.push(index);
	Visited[index] = true;

	// sort(Nodes[index].begin(), Nodes[index].end());
	while (!Q.empty())
	{
		// 큐의 맨 앞에 있는 노드를 꺼내고, 방문 순서에 기록
		int CurrentNode = Q.front();
		Q.pop();

		Result.push_back(CurrentNode);

		for (int i = 0; i < Nodes[CurrentNode].size(); ++i)
		{
			if (!Visited[Nodes[CurrentNode][i]])
			{
				Q.push(Nodes[CurrentNode][i]);
				Visited[Nodes[CurrentNode][i]] = true;
			}
		}
	}
}

void PrintResult()
{
	for (const auto& num : Result)
	{
		cout << num << " ";
	}
	cout << "\n";
	Result.clear();
}