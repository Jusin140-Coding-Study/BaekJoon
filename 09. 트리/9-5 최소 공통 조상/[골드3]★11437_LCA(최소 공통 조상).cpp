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

// �ּ� ���� ����(LCA)
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	// ���� ����Ʈ�� Ʈ�� �����͸� �����մϴ�.
	// Ž�� �˰���(DFS, BFS)�� �̿��� �� ����� ���̸� ���մϴ�.
	// ���̸� ���߱� ���� �� ���� ��带 ���� ���̰� �� ������ �θ� ���� �̵��մϴ�.
	// ���̰� ������ ��� �� �� ��ĭ�� �ø��鼭 �θ� ���� ������ �ݺ��մϴ�.

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

	// BFS�� ���� �θ���, ������ ����Ѵ�.
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
	int iLevel = 1;		// ���� depth(level)
	int iNow_Size = 1;	// ���� depth(level)�� ��� ����?
	int iCount = 0;		// ���� depth���� ���� � ��带 ó���ߴ��� �˷��ִ� ����

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

				// �θ� ���� ���� ����
				Parent[next] = iNow_Index;
				Depth[next] = iLevel;
			}
		}
		// ó���� ��� �� iCount����++
		++iCount;

		// ó���� ��尡 ���� level�� ũ��� ���ٸ�
		if (iCount == iNow_Size)
		{
			iCount = 0;				// ī��Ʈ ������ �ʱ�ȭ ���ְ�,
			iNow_Size = Q.size();	// ���� level�� ũ��� Queue�� ����� �ȴ�.
			++iLevel;				// ���� level�� �Ѿ��.
		}
	}
}

int LCA(int a, int b)
{
	// a�� depth�� ������ ũ�Բ� �������ش�.
	if (Depth[a] < Depth[b])
	{
		int iTemp = a;
		a = b;
		b = iTemp;
	}

	// a�� b�� depth�� ������ ������ a�� ��� �θ���� �÷��ݴϴ�.
	while (Depth[a] != Depth[b])
		a = Parent[a];

	// ���� �θ� ���� ������ �� ��带 ���� �� ĭ�� �÷��ݴϴ�.
	while (a != b)
	{
		a = Parent[a];
		b = Parent[b];
	}

	return a;
}