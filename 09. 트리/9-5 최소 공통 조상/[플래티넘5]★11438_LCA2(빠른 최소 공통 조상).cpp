#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

static int N, M;
static int KMax;
static vector<vector<int>> Tree;
static vector<int> Depth;
static vector<bool> Visited;
static int Parent[21][100001];

void BFS(int iIndex);
int LapidLCA(int a, int b);

// 최소 공통 조상(LCA) 빠르게 구하기
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	Tree = vector<vector<int>>(N + 1, vector<int>());
	Depth = vector<int>(N + 1, 0);
	Visited = vector<bool>(N + 1, 0);

	for (int i = 0; i < N - 1; i++)
	{
		int s, e;
		cin >> s >> e;

		Tree[s].push_back(e);
		Tree[e].push_back(s);
	}

	int iTemp = 1;
	KMax = 0;

	// 노드 개수 N으로 트리를 만들었을 때, 나올 수 있는 높이의 최대치 > 2^k를 만족하는
	// k의 최대값을 구하는 과정(한번에 점프할 수 있는 최대 높이가 높이의 최대치를 넘어서면 안되기 때문)
	while (iTemp <= N)
	{
		iTemp <<= 1;
		++KMax;
	}

	BFS(1);

	// 점화식을 통해 2차원 배열을 채워줍니다.
	for (int k = 1; k <= KMax; ++k)
	{
		for (int n = 1; n <= N; ++n)
		{
			Parent[k][n] = Parent[k - 1][Parent[k - 1][n]];
		}
	}

	cin >> M;

	for (int i = 0; i < M; ++i)
	{
		int a, b;
		cin >> a >> b;
		
		cout << LapidLCA(a, b) << "\n";
	}

	return 0;
}

void BFS(int iIndex)
{
	queue<int> Q;
	Q.push(iIndex);

	Visited[iIndex] = true;
	int iLevel = 1;
	int iNow_Size = 1;
	int iCount = 0;

	while (!Q.empty())
	{
		int iNow_Node = Q.front();
		Q.pop();

		for (const auto next : Tree[iNow_Node])
		{
			if (!Visited[next])
			{
				Visited[next] = true;
				Q.push(next);

				// 바로 위의 부모(next노드의 2^0 층만큼 올라간 부모)를 저장
				Parent[0][next] = iNow_Node;
				Depth[next] = iLevel;
			}
		}
		++iCount;

		// 현재 level을 다 처리했다면, 다음 레벨로 내려간다.
		if (iCount == iNow_Size)
		{
			iCount = 0;
			iNow_Size = Q.size();
			++iLevel;
		}
	}
}

int LapidLCA(int a, int b)
{
	// b의 depth가 무조건 더 깊게끔 세팅합니다.
	if (Depth[a] > Depth[b])
	{
		int iTemp = a;
		a = b;
		b = iTemp;
	}

	// ※ 빠른 깊이 맞추기 ※ -> 2^k층 만큼 이동
	for (int k = KMax; k >= 0; k--)
	{
		if (pow(2, k) <= Depth[b] - Depth[a])
			b = Parent[k][b];
	}
	
	// ※ 빠른 조상 찾기 ※ -> 2^k층 만큼 이동
	for (int k = KMax; k >= 0; k--)
	{
		if (Parent[k][b] != Parent[k][a])
		{
			a = Parent[k][a];
			b = Parent[k][b];
		}
	}

	int iLapidLCA = a;

	// 만약 a와 b가 다르다면, 한칸 위의 부모를 선택합니다.
	if (a != b)
		iLapidLCA = Parent[0][iLapidLCA];

	return iLapidLCA;
}