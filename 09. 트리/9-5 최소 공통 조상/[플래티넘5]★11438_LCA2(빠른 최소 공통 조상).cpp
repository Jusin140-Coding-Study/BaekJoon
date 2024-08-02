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

// �ּ� ���� ����(LCA) ������ ���ϱ�
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

	// ��� ���� N���� Ʈ���� ������� ��, ���� �� �ִ� ������ �ִ�ġ > 2^k�� �����ϴ�
	// k�� �ִ밪�� ���ϴ� ����(�ѹ��� ������ �� �ִ� �ִ� ���̰� ������ �ִ�ġ�� �Ѿ�� �ȵǱ� ����)
	while (iTemp <= N)
	{
		iTemp <<= 1;
		++KMax;
	}

	BFS(1);

	// ��ȭ���� ���� 2���� �迭�� ä���ݴϴ�.
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

				// �ٷ� ���� �θ�(next����� 2^0 ����ŭ �ö� �θ�)�� ����
				Parent[0][next] = iNow_Node;
				Depth[next] = iLevel;
			}
		}
		++iCount;

		// ���� level�� �� ó���ߴٸ�, ���� ������ ��������.
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
	// b�� depth�� ������ �� ��Բ� �����մϴ�.
	if (Depth[a] > Depth[b])
	{
		int iTemp = a;
		a = b;
		b = iTemp;
	}

	// �� ���� ���� ���߱� �� -> 2^k�� ��ŭ �̵�
	for (int k = KMax; k >= 0; k--)
	{
		if (pow(2, k) <= Depth[b] - Depth[a])
			b = Parent[k][b];
	}
	
	// �� ���� ���� ã�� �� -> 2^k�� ��ŭ �̵�
	for (int k = KMax; k >= 0; k--)
	{
		if (Parent[k][b] != Parent[k][a])
		{
			a = Parent[k][a];
			b = Parent[k][b];
		}
	}

	int iLapidLCA = a;

	// ���� a�� b�� �ٸ��ٸ�, ��ĭ ���� �θ� �����մϴ�.
	if (a != b)
		iLapidLCA = Parent[0][iLapidLCA];

	return iLapidLCA;
}