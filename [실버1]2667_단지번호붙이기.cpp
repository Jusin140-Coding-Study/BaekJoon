#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

static int N = 0;
static int iTownCount = 1;
static vector<vector<int>> Graph;
static vector<vector<bool>> Visited;
static vector<int> NumHouse;
void BFS(int i, int j);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	Graph = vector<vector<int>>(N, vector<int>(N, -1));
	Visited = vector<vector<bool>>(N, vector<bool>(N, false));

	for (int i = 0; i < N; ++i)
	{
		string strInput;
		cin >> strInput;

		for (int j = 0; j < N; ++j)
			Graph[i][j] = strInput[j] - '0';
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (0 != Graph[i][j] && !Visited[i][j])
				BFS(i, j);
		}
	}

	cout << iTownCount - 1 << "\n";

	sort(NumHouse.begin(), NumHouse.end());
	for (const auto& numhouse : NumHouse)
		cout << numhouse << "\n";

	return 0;
}

void BFS(int i, int j)
{
	if (Visited[i][j]) return;

	queue<pair<int,int>> Q;
	Q.push(make_pair(i, j));
	Graph[i][j] = iTownCount;

	int iNumHouse = 0;

	while (!Q.empty())
	{
		pair<int, int> iCurNode = Q.front();
		Q.pop();

		if (Visited[iCurNode.first][iCurNode.second]) continue;

		Visited[iCurNode.first][iCurNode.second] = true;
		Graph[iCurNode.first][iCurNode.second] = iTownCount;

		iNumHouse++;

		if (0 <= iCurNode.first - 1 && 0 != Graph[iCurNode.first - 1][iCurNode.second] && !Visited[iCurNode.first - 1][iCurNode.second])
			Q.push(make_pair(iCurNode.first - 1, iCurNode.second));
		if (0 <= iCurNode.second - 1 && 0 != Graph[iCurNode.first][iCurNode.second - 1] && !Visited[iCurNode.first][iCurNode.second - 1])
			Q.push(make_pair(iCurNode.first, iCurNode.second - 1));
		if(iCurNode.first + 1 < N && 0 != Graph[iCurNode.first + 1][iCurNode.second] && !Visited[iCurNode.first + 1][iCurNode.second])
			Q.push(make_pair(iCurNode.first + 1, iCurNode.second));
		if(iCurNode.second + 1 < N && 0 != Graph[iCurNode.first][iCurNode.second + 1] && !Visited[iCurNode.first][iCurNode.second + 1])
			Q.push(make_pair(iCurNode.first, iCurNode.second + 1));
	}

	NumHouse.push_back(iNumHouse);
	iTownCount++;
}