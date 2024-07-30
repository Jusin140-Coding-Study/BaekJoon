#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int Find(int a);
void Union(int a, int b);
static vector<int> Parents;
static vector<vector<int>> Matrix;

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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0; int M = 0;
	cin >> N >> M;

	// 대표 노드 배열 초기화
	Parents.resize(N + 1);
	for (int i = 1; i <= N; ++i)
		Parents[i] = i;

	// 지도 초기화
	Matrix = vector<vector<int>>(N, vector<int>(M, 0));

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> Matrix[i][j];
		}
	}


	
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
		return Parents[a] = Find(Parents[a]);
}

// i, j가 섬인지 체크해주는 함수
void CheckIsland(int i, int j)
{

}