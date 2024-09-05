#include <iostream>
#include <vector>
using namespace std;

static vector<vector<int>> graph;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	graph = vector<vector<int>>(n + 1, vector<int>(n + 1, 9'900'001));

	for (int i = 0; i < m; ++i)
	{
		int s, e, w;
		cin >> s >> e >> w;

		if(w < graph[s][e])
			graph[s][e] = w;
	}

	for (int i = 1; i <= n; ++i)
		graph[i][i] = 0;

	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
			{
				if (graph[i][j] > graph[i][k] + graph[k][j])
				{
					graph[i][j] = graph[i][k] + graph[k][j];
				}
			}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (9'900'001 == graph[i][j])
				cout << 0 << " ";
			else
				cout << graph[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}