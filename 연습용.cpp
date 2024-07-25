#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0; int E = 0;
	cin >> N >> E;

	int StartIndex = 0;
	cin >> StartIndex;

	vector<vector<pair<int, int>>> NearList(N + 1, vector<pair<int, int>>());
	vector<int> Shortest(N + 1, 2147483647);
	vector<bool> Visited(N + 1, false);
	for (int i = 0; i < E; ++i)
	{
		int u = 0; int v = 0; int w = 0;
		cin >> u >> v >> w;

		NearList[u].push_back({ v, w });
	}

	priority_queue<int> Q;
	Q.push(StartIndex);
	Shortest[StartIndex] = 0;

	while (!Q.empty())
	{
		int curNode = Q.top();
		Q.pop();
		Visited[curNode] = true;

		for (auto& nextNode : NearList[curNode])
		{
			if (!Visited[nextNode.first])
			{
				Shortest[nextNode.first] = min(Shortest[nextNode.first], Shortest[curNode] + nextNode.second);
				Q.push(nextNode.first);
			}
		}
	}

	for (int i = 1; i <= N; ++i)
	{
		if (i == StartIndex)
			cout << 0 << "\n";
		else if (2147483647 == Shortest[i])
			cout << "INF" << "\n";
		else
			cout << Shortest[i] << "\n";
	}
}