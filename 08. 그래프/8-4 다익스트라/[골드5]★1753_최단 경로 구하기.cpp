#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int V = 0; int E = 0; int StartIndex = 0;
	cin >> V;
	cin >> E;

	cin >> StartIndex;

	vector<vector<pair<int, int>>> NearList(V + 1, vector<pair<int, int>>());
	vector<int> Shortest(V + 1, INT_MAX);
	vector<bool> Visited(V + 1, false);
	priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int,int>>> PQ;

	for (int i = 0; i < E; ++i)
	{
		int u = 0; int v = 0; int w = 0;
		cin >> u >> v >> w;
		NearList[u].push_back({ v, w });
	}

	PQ.push({ 0, StartIndex });
	Shortest[StartIndex] = 0;

	while (!PQ.empty())
	{
		pair<int, int> curNode = PQ.top();
		PQ.pop();

		int curIndex = curNode.second;
		if (Visited[curIndex])
			continue;

		Visited[curIndex] = true;

		for (int i = 0; i < NearList[curIndex].size(); ++i)
		{
			pair<int, int> node = NearList[curIndex][i];

			int nextIndex = node.first;
			int weight = node.second;

			if (Shortest[nextIndex] > Shortest[curIndex] + weight)
			{
				Shortest[nextIndex] = Shortest[curIndex] + weight;
				PQ.push({ Shortest[nextIndex], nextIndex });
			}
		}
	}

	for (int i = 1; i <= V; ++i)
	{
		if (Visited[i])
			cout << Shortest[i] << "\n";
		else
			cout << "INF" << "\n";
	}
}