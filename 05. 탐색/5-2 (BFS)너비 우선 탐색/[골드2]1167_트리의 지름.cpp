#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> Node;
vector<vector<Node>> V;
vector<bool> Visited;
vector<int> D;

int BFS(int nodeindex);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;
	cin >> N;

	V = vector<vector<Node>>(N + 1, vector<Node>(0, {0, 0}));
	D = vector<int>(N + 1, 0);
	Visited = vector<bool>(N + 1, 0);

	for (int i = 1; i <= N; ++i)
	{
		int DotIndex = 0;
		int Destination = 0;
		int Distance = 0;

		cin >> DotIndex;
		while (true)
		{
			cin >> Destination;

			if (-1 == Destination)
				break;

			cin >> Distance;

			V[DotIndex].push_back({ Destination, Distance });
		}
	}

	int FirstMaxIndex = BFS(N / 2);

	fill(D.begin(), D.end(), 0);
	fill(Visited.begin(), Visited.end(), false);

	int SecondMaxIndex = BFS(FirstMaxIndex);

	cout << D[SecondMaxIndex];
}

int BFS(int nodeindex)
{
	queue<int> Q;

	Q.push(nodeindex);
	Visited[nodeindex] = true;

	while (!Q.empty())
	{
		int CurNode = Q.front();
		Q.pop();
		
		for (int i = 0; i < V[CurNode].size(); ++i)
		{
			if (!Visited[V[CurNode][i].first])
			{
				Q.push(V[CurNode][i].first);
				Visited[V[CurNode][i].first] = true;
				D[V[CurNode][i].first] = D[CurNode] + V[CurNode][i].second;
			}
		}
	}

	int MaxDistance = 0;
	int MaxIndex = 0;
	for (int i = 0; i < D.size(); ++i)
	{
		if (MaxDistance < D[i])
		{
			MaxDistance = D[i];
			MaxIndex = i;
		}
	}

	return MaxIndex;
}