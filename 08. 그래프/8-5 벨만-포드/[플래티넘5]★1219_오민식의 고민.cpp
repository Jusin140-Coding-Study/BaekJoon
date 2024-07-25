#include <iostream>
#include <tuple>
#include <vector>
#include <limits.h>
using namespace std;

typedef tuple<int, int, int> edge;
static vector<edge> EdgeList;
static vector<long> Longest;
static vector<long> CityMoney;
void Bellmanford(int start, int End, int citynum, int edgenum);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0; int Start = 0; int End = 0; int M = 0;
	cin >> N >> Start >> End >> M;

	EdgeList = vector<edge>();
	Longest = vector<long>(N, LONG_MIN);
	CityMoney = vector<long>(N, 0);

	for (int i = 0; i < M; ++i)
	{
		int u = 0; int v = 0; int w = 0;
		cin >> u >> v >> w;

		EdgeList.push_back(make_tuple(u, v, w));
	}

	for (int i = 0; i < N; ++i)
	{
		cin >> CityMoney[i];
	}

	Bellmanford(Start, End, N, M);

	if (Longest[End] == LONG_MIN)
		cout << "gg" << "\n";
	else if (Longest[End] == LONG_MAX)
		cout << "Gee" << "\n";
	else
		cout << Longest[End] << "\n";
}

void Bellmanford(int start, int End, int citynum, int edgenum)
{
	Longest[start] = CityMoney[start];

	// 양수 사이클이 전파되도록 충분히 큰 수로 반복
	for (int i = 0; i <= citynum + 50; ++i)
	{
		for (int j = 0; j < edgenum; ++j)
		{
			edge curEdge = EdgeList[j];
			int Start	= get<0>(curEdge);
			int End		= get<1>(curEdge);
			int Cost	= get<2>(curEdge);

			// 시작 노드가 미방문 노드이면 continue;
			if (Longest[Start] == LONG_MIN)
				continue;

			// 시작 노드가 양수 사이클에 연결된 노드라면, 종료 노드도 연결 노드로 계산
			else if (Longest[Start] == LONG_MAX)
				Longest[End] = LONG_MAX;

			// 만약 돈을 더 벌 수 있는 경로라면 갱신
			else if (Longest[End] < Longest[Start] - Cost + CityMoney[End])
			{
				Longest[End] = Longest[Start] - Cost + CityMoney[End];

				// N - 1번 반복 이후 갱신된다면 종료 노드는 양수 사이클 연결 노드로 변경
				if (i >= citynum - 1)
					Longest[End] = LONG_MAX;
			}
		}
	}
}