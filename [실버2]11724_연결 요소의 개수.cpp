#include <iostream>
#include <queue>
using namespace std;

static int iResult = 0;
static vector<vector<int>> Graph;
static vector<bool> Visited;
void BFS(int iIndex);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	Graph = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));
	Visited = vector<bool>(N + 1, false);

	for (int i = 0; i < M; ++i)
	{
		int s, e;
		cin >> s >> e;

		Graph[s].push_back(e);
		Graph[e].push_back(s);
	}

	for (int i = 1; i <= N; ++i)
		BFS(i);

	cout << iResult;

	return 0;
}

void BFS(int iIndex)
{
	if (Visited[iIndex]) return;

	queue<int> Q;
	Q.push(iIndex);
	Visited[iIndex] = true;

	iResult++;

	while (!Q.empty())
	{
		int iCurNode = Q.front();
		Q.pop();

		for (const auto& node : Graph[iCurNode])
		{
			if (!Visited[node])
			{
				Q.push(node);
				Visited[node] = true;
			}
		}
	}
}