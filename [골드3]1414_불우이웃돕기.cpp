#include <iostream>
#include <vector>
#include <queue>
using namespace std;

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

static vector<int> Parents;
static priority_queue<Edge, vector<Edge>, greater<>> pQ;
int Find(int a);
void Union(int a, int b);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0; int Result = 0;
	cin >> N;

	// 대표 노드 배열 초기화
	Parents = vector<int>(N, 0);
	for (int i = 0; i < N; ++i)
		Parents[i] = i;

	// 컴퓨터의 연결 관계
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			char input = 0;
			cin >> input;

			// 0인 경우
			if ('0' == input)
				continue;

			// 엣지 저장
			if (96 < input)
			{
				Result += input - 96;
				pQ.push(Edge{ i, j, input - 96 });
			}
			else
			{
				Result += input - 38;
				pQ.push(Edge{ i, j, input - 38 });
			}
		}
	}

	int nodeCnt = N;
	int useEdge = 0;

	while (!pQ.empty())
	{
		Edge now = pQ.top();
		pQ.pop();

		if (Find(now.s) != Find(now.e))
		{
			Union(now.s, now.e);
			++useEdge;
			Result -= now.v;
		}
	}

	if (useEdge == nodeCnt - 1)
		cout << Result << "\n";
	else
		cout << -1 << "\n";

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