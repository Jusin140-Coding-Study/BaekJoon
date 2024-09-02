#include <iostream>
#include <queue>
using namespace std;

static int N, M;
typedef pair<int, int> Index;
static int iResult = 0;
static vector<vector<int>> Graph;
static vector<vector<bool>> Visited;
void BFS(int i, int j);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	Graph = vector<vector<int>>(N, vector<int>(M, -1));
	Visited = vector<vector<bool>>(N, vector<bool>(M));

	for (int i = 0; i < N; ++i)
	{
		string strInput;
		cin >> strInput;

		for (int j = 0; j < M; ++j)
			Graph[i][j] = strInput[j] - '0';
	}

	BFS(0, 0);
	cout << iResult;

	return 0;
}

bool Check(int i, int j, queue<Index>& q, int iDepth)
{
	if (i >= N || j >= M || i < 0 || j < 0) return false;
	if (Visited[i][j]) return false;
	if (0 == Graph[i][j]) return false;

	Visited[i][j] = true;
	Graph[i][j] = iDepth + 1;

	if (i == N - 1 && j == M - 1) 
	{ 
		iResult = Graph[i][j];
		return true; 
	}

	q.push(make_pair(i, j));

	return false;
}

void BFS(int i, int j)
{
	queue<Index> Q;
	Q.push(make_pair(i, j));

	Visited[i][j] = true;

	while (!Q.empty())
	{
		Index curNode = Q.front();
		Q.pop();
		int x = curNode.first;
		int y = curNode.second;
		int iDepth = Graph[x][y];

		if (Check(x + 1, y, Q, iDepth)) break;
		if (Check(x, y + 1, Q, iDepth)) break;
		if (Check(x - 1, y, Q, iDepth)) break;
		if (Check(x, y - 1, Q, iDepth)) break;
	}
}