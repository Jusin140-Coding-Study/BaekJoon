#include <iostream>
#include <vector>
using namespace std;

static vector<vector<int>> Parties;
static vector<int> Trues;
static vector<int> Parents;
void Union(int a, int b);
int Find(int a);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// N : ����� ��, M : ��Ƽ�� ��
	int N = 0; int M = 0;
	int Result = 0;
	cin >> N >> M;

	// ��ǥ��� �迭 �ʱ�ȭ
	Parents = vector<int>(N + 1, 0);
	for (int i = 0; i <= N; ++i)
		Parents[i] = i;

	// T : ������ �ƴ� ����� ��
	int T = 0;
	cin >> T;
	
	Trues = vector<int>(T, 0);
	for (int i = 0; i < T; ++i)
		cin >> Trues[i];

	// ��Ƽ ���� ����
	Parties = vector<vector<int>>(M, vector<int>());
	for (int i = 0; i < M; ++i)
	{
		int partysize = 0;
		cin >> partysize;

		for (int j = 0; j < partysize; ++j)
		{
			int temp = 0;
			cin >> temp;
			Parties[i].push_back(temp);
		}
	}

	// �� ��Ƽ�� ������� �ϳ��� �׷����� Union
	for (int i = 0; i < M; ++i)
	{
		int first = Parties[i][0];
		for (int j = 1; j < Parties[i].size(); ++j)
			Union(first, Parties[i][j]);
	}

	// �� ��Ƽ�� ��ȸ�ϸ�, ������ �ƴ� ����� ���� �Ҽ����� �˻�
	for (int i = 0; i < M; ++i)
	{
		// �� ��Ƽ�� �� ���Ͽ����� �� ������ ������, �ƹ��� �Ѹ� ��Ƽ� �˻��ϸ� ��
		int someone = Parties[i][0];
		bool IsAbleToLie = true;

		for (int j = 0; j < T; ++j)
		{
			if (Find(someone) == Find(Trues[j]))
			{
				IsAbleToLie = false;
				break;
			}
		}

		if (IsAbleToLie)
			++Result;
	}

	cout << Result;
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
	if (Parents[a] == a)
		return a;
	else
		return Parents[a] = Find(Parents[a]);
}