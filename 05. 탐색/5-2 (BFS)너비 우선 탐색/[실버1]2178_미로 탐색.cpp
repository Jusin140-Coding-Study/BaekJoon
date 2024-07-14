#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> Index;
bool IsValidIndex(queue<Index>& q, int i, int j);
void DFS(int i, int j);
vector<vector<int>> Maze;
vector<vector<bool>> Visited;
static int N;
static int M;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	N = 0;
	M = 0;
	cin >> N >> M;
	Maze = vector<vector<int>>(N, vector<int>(M, 0));
	Visited = vector<vector<bool>>(N, vector<bool>(M, false));

	for (int i = 0; i < N; ++i)
	{
		string Input = "";
		cin >> Input;

		for (int j = 0; j < Input.size(); ++j)
			Maze[i][j] = Input[j] - '0';
	}

	DFS(0, 0);
	cout << Maze[N-1][M-1];
}

void DFS(int i, int j)
{
	queue<Index> Q;

	Visited[i][j] = true;
	Q.push({ i, j });

	while (!Q.empty())
	{
		Index CurIndex = Q.front();
		Q.pop();
		// Result++; 여기서 깊이를 업데이트 하면 안됨.

		// 도착지에 도착한 경우 DFS를 종료
		if (CurIndex.first == N && CurIndex.second == M)
			break;

		// 한 너비의 탐색을 마치고 다음 깊이로 넘어가는 경우, 깊이값을 업데이트 한다.
		if(IsValidIndex(Q, CurIndex.first + 1, CurIndex.second)) Maze[CurIndex.first + 1][CurIndex.second] = Maze[CurIndex.first][CurIndex.second] + 1;
		if(IsValidIndex(Q, CurIndex.first, CurIndex.second + 1)) Maze[CurIndex.first][CurIndex.second + 1] = Maze[CurIndex.first][CurIndex.second] + 1;
		if(IsValidIndex(Q, CurIndex.first - 1, CurIndex.second)) Maze[CurIndex.first - 1][CurIndex.second] = Maze[CurIndex.first][CurIndex.second] + 1;
		if(IsValidIndex(Q, CurIndex.first, CurIndex.second - 1)) Maze[CurIndex.first][CurIndex.second - 1] = Maze[CurIndex.first][CurIndex.second] + 1;
	}
}

bool IsValidIndex(queue<Index>& q, int i, int j)
{
	// 인덱스 범위 검사
	if (i < 0 || i > N - 1) return false;
	if (j < 0 || j > M - 1) return false;

	// 방문 여부 검사
	if (Visited[i][j]) return false;

	// 0인지 1인지 체크
	if (0 == Maze[i][j]) return false;

	q.push({ i, j });
	Visited[i][j] = true;

	return true;
}