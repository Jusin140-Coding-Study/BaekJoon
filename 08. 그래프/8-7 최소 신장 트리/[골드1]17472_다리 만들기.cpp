#include <iostream>
#include <vector>
#include <queue>
using namespace std;

enum class Direction
{
	UP			= 0,
	DOWN		= 1,
	LEFT		= 2,
	RIGHT		= 3,
	ENUM_END	= 4,
};

struct Edge
{
	int s = 0;
	int e = 0;
	int v = 0;

	bool operator > (const Edge& temp) const
	{
		return v > temp.v;
	}
};

static int IslandCnt;
static int N; static int M;
static Edge ReturnEdge;
static vector<bool> IslandCheck;
static vector<int> Parents;
static vector<vector<int>> Matrix;
static priority_queue<Edge, vector<Edge>, greater<>> pQ;
int Find(int a);
void Union(int a, int b);
void CheckIsland(int i, int j);
Edge MakeBridge(int i, int j, int start_island, Direction dir);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	// 지도 초기화
	Matrix = vector<vector<int>>(N, vector<int>(M, 0));

	// 섬 체크 배열 초기화
	IslandCheck = vector<bool>(9, false);

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> Matrix[i][j];
		}
	}

	IslandCnt = 2;

	// Matrix를 통해 섬 제작
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (0 != Matrix[i][j] && false == IslandCheck[Matrix[i][j]])
			{
				CheckIsland(i, j);
				IslandCheck[IslandCnt] = true;
				IslandCnt++;
			}
		}
	}

	// 임시
	//for (int i = 0; i < N; ++i)
	//{
	//	for (int j = 0; j < M; ++j)
	//	{
	//		cout << Matrix[i][j] << " ";
	//	}
	//	cout << "\n";
	//}

	// 대표 노드 배열 초기화
	Parents.resize(8);
	for (int i = 2; i <= 7; ++i)
		Parents[i] = i;

	// 다리 제작
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (0 != Matrix[i][j])
			{
				for (int k = (int)Direction::UP; k <= (int)Direction::RIGHT; ++k)
				{
					ReturnEdge = { 0, 0, 0 };
					Edge tempEdge = MakeBridge(i, j, Matrix[i][j], (Direction)k);

					// 만들어진 다리의 길이가 2 이상인 경우 우선순위 큐에 넣는다.
					if (2 <= tempEdge.v && 0 != tempEdge.s && 0 != tempEdge.e)
						pQ.push(tempEdge);
				}
			}
		}
	}

	// 불가능한 경우?
	if (pQ.empty())
	{
		cout << -1 << "\n";
		return 0;
	}

	// 최소 신장 트리 수행
	int nodeCnt = IslandCnt - 2;
	int useEdge = 0;
	int result = 0;

	while (!pQ.empty())
	{
		Edge now = pQ.top();
		pQ.pop();

		if (Find(now.s) != Find(now.e))
		{
			Union(now.s, now.e);
			result = result + now.v;
			++useEdge;
		}
	}

	if (useEdge == nodeCnt - 1)
		cout << result;
	else
		cout << -1;
	
	return 0;
}

void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);

	if (a != b)
		Parents[b] = a;
}

int Find(int a)
{
	if (a == Parents[a])
		return a;
	else
	{
		if (0 == a || 1 == a) return 0;
		return Parents[a] = Find(Parents[a]);
	}
}

// Matrix[i][j]가 유효한 인덱스인지 검사해주는 함수
bool EnableIndex(int i, int j)
{
	if (i < 0 || i >= N || j < 0 || j >= M)
		return false;
	return true;
}

// i, j가 섬인지 재귀적으로 체크하여 섬을 만드는 함수.
void CheckIsland(int i, int j)
{
	// 해당 인덱스의 상하좌우를 탐색하며 IslandCnt변수로 바꿔준다.
	// 재귀적으로 4 방향을 탐색하되, 예외 상황을 고려한다.

	/* 가운데 */
	if (0 != Matrix[i][j] && IslandCnt != Matrix[i][j])
		Matrix[i][j] = IslandCnt;

	/* 상 */
	if (0 <= j - 1 && 0 != Matrix[i][j - 1] && IslandCnt != Matrix[i][j - 1])
	{
		Matrix[i][j - 1] = IslandCnt;
		CheckIsland(i, j - 1);
	}

	/* 하 */
	if (M > j + 1 && 0 != Matrix[i][j + 1] && IslandCnt != Matrix[i][j + 1])
	{
		Matrix[i][j + 1] = IslandCnt;
		CheckIsland(i, j + 1);
	}

	/* 좌 */
	if (0 <= i - 1 && 0 != Matrix[i - 1][j] && IslandCnt != Matrix[i - 1][j])
	{
		Matrix[i - 1][j] = IslandCnt;
		CheckIsland(i - 1, j);
	}

	/* 우 */
	if (N > i + 1 && 0 != Matrix[i + 1][j] && IslandCnt != Matrix[i + 1][j])
	{
		Matrix[i + 1][j] = IslandCnt;
		CheckIsland(i + 1, j);
	}	
}

// start_island 기준 4방향을 탐색하여 다리를 만들어주는 함수
Edge MakeBridge(int i, int j, int start_island, Direction dir)
{
	switch (dir)
	{
	case Direction::LEFT:
	{
		if (EnableIndex(i, j - 1))
		{
			// 출발 섬과 번호가 다르고, 0이 아닌 경우
			if (start_island != Matrix[i][j - 1] && 0 != Matrix[i][j - 1])
			{
				// 다른 섬이 발견됨.
				ReturnEdge.s = start_island;
				ReturnEdge.e = Matrix[i][j - 1];
				return ReturnEdge;
			}
			else if (start_island == Matrix[i][j - 1])
			{
				return Edge{ 0, 0, 0 };
			}
			else
			{
				++ReturnEdge.v;
				MakeBridge(i, j - 1, start_island, dir);
			}
		}
		
		break;
	}
	case Direction::RIGHT:
	{
		if (EnableIndex(i, j + 1))
		{
			if (start_island != Matrix[i][j + 1] && 0 != Matrix[i][j + 1])
			{
				// 다른 섬이 발견됨.
				ReturnEdge.s = start_island;
				ReturnEdge.e = Matrix[i][j + 1];
				return ReturnEdge;
			}
			else if (start_island == Matrix[i][j + 1])
			{
				return Edge{ 0, 0, 0 };
			}
			else
			{
				++ReturnEdge.v;
				MakeBridge(i, j + 1, start_island, dir);
			}
		}

		break;
	}
	case Direction::UP:
	{
		if (EnableIndex(i - 1, j))
		{
			if (start_island != Matrix[i - 1][j] && 0 != Matrix[i - 1][j])
			{
				// 다른 섬이 발견됨.
				ReturnEdge.s = start_island;
				ReturnEdge.e = Matrix[i - 1][j];
				return ReturnEdge;
			}
			else if (start_island == Matrix[i - 1][j])
			{
				return Edge{ 0, 0, 0 };
			}
			else
			{
				++ReturnEdge.v;
				MakeBridge(i - 1, j, start_island, dir);
			}
		}

		break;
	}
	case Direction::DOWN:
	{
		if (EnableIndex(i + 1, j))
		{
			if (start_island != Matrix[i + 1][j] && 0 != Matrix[i + 1][j])
			{
				// 다른 섬이 발견됨.
				ReturnEdge.s = start_island;
				ReturnEdge.e = Matrix[i + 1][j];
				return ReturnEdge;
			}
			else if (start_island == Matrix[i + 1][j])
			{
				return Edge{ 0, 0, 0 };
			}
			else
			{
				++ReturnEdge.v;
				MakeBridge(i + 1, j, start_island, dir);
			}
		}

		break;
	}
	}

	// 다른 섬이 발견되지 않음
	return ReturnEdge;
}