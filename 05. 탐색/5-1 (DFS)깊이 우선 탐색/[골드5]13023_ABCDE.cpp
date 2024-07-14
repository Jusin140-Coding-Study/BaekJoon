#include <iostream>
#include <vector>
using namespace std;

static vector<vector<int>> Nodes;
static vector<bool> Visited;
void DFS(int index, int depth);
static bool IsExist;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;
	int M = 0;
	cin >> N >> M;

	// 인접 리스트와 방문 배열 초기화
	Nodes = vector<vector<int>>(N, vector<int>(0, 0));
	Visited = vector<bool>(N, false);
	IsExist = false;

	for (int i = 0; i < M; ++i)
	{
		int u = 0;
		int v = 0;
		cin >> u >> v;

		Nodes[u].push_back(v);
		Nodes[v].push_back(u);
	}

	for (int i = 0; i < N; ++i)
	{
		if (!IsExist)
			DFS(i, 1);
	}

	if (IsExist)
		cout << 1;
	else
		cout << 0;
}

void DFS(int index, int depth)
{
	if (5 == depth || IsExist)
	{
		IsExist = true;
		return;
	}

	Visited[index] = true;

	for (int i = 0; i < Nodes[index].size(); ++i)
	{
		if (!Visited[Nodes[index][i]])
			DFS(Nodes[index][i], depth + 1);
	}

	// 싹싹 핥는게 아니고 어떤 경우의 수를 찾는 것이므로, 방문후 나올 때 방문 체크를 풀어준다?
	Visited[index] = false;
}