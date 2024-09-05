#include <iostream>
#include <queue>
using namespace std;

static vector<vector<int>> graph;
static vector<int> inner;
static vector<int> result;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	graph = vector<vector<int>>(n + 1, vector<int>());
	inner = vector<int>(n + 1, 0);

	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;

		graph[a].push_back(b);
		inner[b]++;
	}

	queue<int> Q;
	for (int i = 1; i <= n; ++i)
	{
		if (0 == inner[i])
			Q.push(i);
	}

	while (!Q.empty())
	{
		int curIndex = Q.front();
		Q.pop();

		result.push_back(curIndex);

		for (const auto& node : graph[curIndex])
		{
			inner[node]--;
			if (0 == inner[node])
				Q.push(node);
		}
	}

	for (const auto& index : result)
		cout << index << " ";

	return 0;
}