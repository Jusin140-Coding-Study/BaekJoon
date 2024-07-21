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

	// N : 사람의 수, M : 파티의 수
	int N = 0; int M = 0;
	int Result = 0;
	cin >> N >> M;

	// 대표노드 배열 초기화
	Parents = vector<int>(N + 1, 0);
	for (int i = 0; i <= N; ++i)
		Parents[i] = i;

	// T : 진실을 아는 사람의 수
	int T = 0;
	cin >> T;
	
	Trues = vector<int>(T, 0);
	for (int i = 0; i < T; ++i)
		cin >> Trues[i];

	// 파티 정보 저장
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

	// 각 파티의 사람들을 하나의 그룹으로 Union
	for (int i = 0; i < M; ++i)
	{
		int first = Parties[i][0];
		for (int j = 1; j < Parties[i].size(); ++j)
			Union(first, Parties[i][j]);
	}

	// 각 파티를 순회하며, 진실을 아는 사람과 같은 소속인지 검사
	for (int i = 0; i < M; ++i)
	{
		// 각 파티를 한 유니온으로 다 묶었기 때문에, 아무나 한명 잡아서 검사하면 됨
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