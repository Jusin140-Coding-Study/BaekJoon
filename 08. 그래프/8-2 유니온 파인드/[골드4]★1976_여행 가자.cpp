#include <iostream>
#include <vector>
using namespace std;

static vector<int> Parent;
static vector<vector<int>> V;
static vector<int> R;
void Union(int a, int b);
int Find(int a);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0; int M = 0;
	cin >> N;
	cin >> M;

	Parent = vector<int>(N + 1, 0);
	R = vector<int>(M + 1, 0);
	V = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));

	// 대표노드 배열 초기화
	for (int i = 1; i <= N; ++i)
		Parent[i] = i;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			cin >> V[i][j];

			if (V[i][j])
				Union(i, j);
		}
	}

	for (int i = 1; i <= M; ++i)
	{
		cin >> R[i];
	}

	int first = Find(R[1]);
	bool bConnect = true;
	for (int i = 2; i <= M; ++i)
	{
		if (Find(R[i]) != first)
		{
			cout << "NO" << "\n";
			bConnect = false;
			break;
		}
	}

	if (bConnect)
		cout << "YES" << "\n";
}

void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);

	if (a != b)
		Parent[b] = a;
}

int Find(int a)
{
	if (Parent[a] == a)
		return a;
	else
		return Parent[a] = Find(Parent[a]);
}