#include <iostream>
#include <vector>
using namespace std;

static vector<vector<int>> NearProcession;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0; int M = 0;
	cin >> N;
	cin >> M;

	NearProcession = vector<vector<int>>(N + 1, vector<int>(N + 1, 10000001));
	for (int i = 1; i <= N; ++i)
	{
		NearProcession[i][i] = 0;
	}

	for (int i = 0; i < M; ++i)
	{
		int u = 0; int v = 0; int w = 0;
		cin >> u >> v >> w;

		if(NearProcession[u][v] > w)
			NearProcession[u][v] = w;
	}

	for(int k = 1; k <= N; ++k)
	{
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= N; ++j)
			{
				if(NearProcession[i][j] > NearProcession[i][k] + NearProcession[k][j])
					NearProcession[i][j] = NearProcession[i][k] + NearProcession[k][j];
			}
		}
	}
	
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			if (10000001 != NearProcession[i][j])
				cout << NearProcession[i][j] << " ";
			else
				cout << 0 << " ";
		}

		cout << "\n";
	}
}