#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> V;
vector<int> Visited;
vector<int> Result;
void BFS(int index);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0; int M = 0; int K = 0; int X = 0;
	cin >> N >> M >> K >> X;

	V = vector<vector<int>>(N + 1, vector<int>());
	Visited = vector<int>(N + 1, -1);

	for (int i = 0; i < M; ++i)
	{
		int Src = 0;
		int Dst = 0;

		cin >> Src >> Dst;
		V[Src].push_back(Dst);
	}

	BFS(X);
	for (int i = 0; i <= N; ++i)
	{
		if (K == Visited[i])
		{
			Result.push_back(i);
		}
	}

	if (!Result.empty())
	{
		sort(Result.begin(), Result.end());

		for (const auto& iter : Result)
			cout << iter << "\n";
	}
	else
	{
		cout << -1 << "\n";
	}

	return 0;
}

void BFS(int index)
{
	queue<int> Q;
	Q.push(index);
	Visited[index]++;

	while (!Q.empty())
	{
		int curNode = Q.front();
		Q.pop();

		for (const auto& iter : V[curNode])
		{
			if (-1 == Visited[iter])
			{
				Visited[iter] = Visited[curNode] + 1;
				Q.push(iter);
			}
		}
	}
}