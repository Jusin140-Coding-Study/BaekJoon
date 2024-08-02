#include <iostream>
#include <vector>
#include <queue>
using namespace std;

static int N, M;
static vector<vector<int>> Tree;
static vector<int> Depth;
static vector<int> Parent;
static vector<bool> Visited;

void BFS(int iIndex);
int LCA(int a, int b);

// 최소 공통 조상(LCA)
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	// 인접 리스트로 트리 데이터를 구현합니다.
	// 탐색 알고리즘(DFS, BFS)을 이용해 각 노드의 깊이를 구합니다.
	// 깊이를 맞추기 위해 더 깊은 노드를 같은 깊이가 될 때까지 부모 노드로 이동합니다.
	// 깊이가 맞춰진 경우 둘 다 한칸씩 올리면서 부모가 같을 때까지 반복합니다.

	Tree = vector<vector<int>>(N + 1, vector<int>());
	Depth = vector<int>(N + 1, 0);
	Parent = vector<int>(N + 1, 0);
	Visited = vector<bool>(N + 1, false);

	for (int i = 0; i < N - 1; i++)
	{
		int s, e;
		cin >> s >> e;

		Tree[s].push_back(e);
		Tree[e].push_back(s);
	}

	// BFS를 통해 부모노드, 뎁스를 기록한다.
	BFS(1);

	cin >> M;

	for (int i = 0; i < M; ++i)
	{
		int a, b;
		cin >> a >> b;

		cout << LCA(a, b) << "\n";
	}

	return 0;
}

void BFS(int iIndex)
{
	queue<int> Q;
	Q.push(iIndex);

	Visited[iIndex] = true;
	int iLevel = 1;		// 현재 depth(level)
	int iNow_Size = 1;	// 현재 depth(level)의 노드 개수?
	int iCount = 0;		// 현재 depth에서 내가 몇개 노드를 처리했는지 알려주는 변수

	while (!Q.empty())
	{
		int iNow_Index = Q.front();
		Q.pop();

		for (const auto next : Tree[iNow_Index])
		{
			if (!Visited[next])
			{
				Visited[next] = true;
				Q.push(next);

				// 부모 노드와 깊이 저장
				Parent[next] = iNow_Index;
				Depth[next] = iLevel;
			}
		}
		// 처리한 노드 당 iCount변수++
		++iCount;

		// 처리한 노드가 현재 level의 크기와 같다면
		if (iCount == iNow_Size)
		{
			iCount = 0;				// 카운트 변수를 초기화 해주고,
			iNow_Size = Q.size();	// 현재 level의 크기는 Queue의 사이즈가 된다.
			++iLevel;				// 다음 level로 넘어간다.
		}
	}
}

int LCA(int a, int b)
{
	// a의 depth가 무조건 크게끔 스왑해준다.
	if (Depth[a] < Depth[b])
	{
		int iTemp = a;
		a = b;
		b = iTemp;
	}

	// a와 b의 depth가 같아질 때까지 a를 계속 부모노드로 올려줍니다.
	while (Depth[a] != Depth[b])
		a = Parent[a];

	// 같은 부모가 나올 때까지 두 노드를 같이 한 칸씩 올려줍니다.
	while (a != b)
	{
		a = Parent[a];
		b = Parent[b];
	}

	return a;
}