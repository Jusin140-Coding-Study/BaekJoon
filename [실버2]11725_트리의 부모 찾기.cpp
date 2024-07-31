#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static vector<vector<int>> Tree;
static vector<bool> Visited;
static vector<int> Result;
void DFS(int index);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;
	cin >> N;

	Tree = vector<vector<int>>(N + 1, vector<int>());
	Visited = vector<bool>(N + 1, false);
	Result = vector<int>(N + 1, 0);
	
	for (int i = 0; i < N - 1; ++i)
	{
		int Linput = 0; int Rinput = 0;
		cin >> Linput >> Rinput;

		Tree[Linput].push_back(Rinput);
		Tree[Rinput].push_back(Linput);
	}

	DFS(1);

	for (int i = 2; i <= N; ++i)
		cout << Result[i] << "\n";

	return 0;
}

void DFS(int index)
{
	Visited[index] = true;

	for (int i = 0; i < Tree[index].size(); ++i)
	{
		if (!Visited[Tree[index][i]])
		{
			Result[Tree[index][i]] = index;
			DFS(Tree[index][i]);
		}
	}
}