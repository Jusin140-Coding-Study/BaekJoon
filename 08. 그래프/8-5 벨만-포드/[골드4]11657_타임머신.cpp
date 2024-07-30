#include <iostream>
#include <tuple>
#include <vector>
#include <limits.h>
using namespace std;

typedef tuple<int, int, int> edge;
static vector<edge> EdgeList;
static vector<long> Shortest;
static bool IsMinusLoop;
void Bellmanford(int start, int citynum, int edgenum);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0; int M = 0;
	cin >> N >> M;

	// 벨만-포드 알고리즘 : 엣지 중심의 알고리즘이다.
	// 그래서 엣지 리스트로 구현한다.
	EdgeList = vector<edge>();
	Shortest = vector<long>(N + 1, LONG_MAX);

	for (int i = 0; i < M; ++i)
	{
		int A = 0; int B = 0; int C = 0;
		cin >> A >> B >> C;

		EdgeList.push_back(make_tuple(A, B, C));
	}

	IsMinusLoop = false;
	Bellmanford(1, N, M);

	if (IsMinusLoop)
	{
		cout << -1 << "\n";
	}
	else
	{
		for (int i = 2; i <= N; ++i)
		{
			if (LONG_MAX == Shortest[i])
			{
				cout << -1 << "\n";
			}
			else
			{
				cout << Shortest[i] << "\n";
			}
		}
	}
}

void Bellmanford(int start, int citynum, int edgenum)
{
	Shortest[start] = 0;

	for (int i = 1; i < citynum; ++i)
	{
		for (int j = 0; j < edgenum; ++j)
		{
			edge curEdge = EdgeList[j];
			int Start = get<0>(curEdge);
			int End = get<1>(curEdge);
			int Time = get<2>(curEdge);

			if (Shortest[Start] != LONG_MAX &&
				Shortest[End] > Shortest[Start] + Time)
			{
				Shortest[End] = Shortest[Start] + Time;
			}
		}
	}

	for (int i = 0; i < edgenum; ++i)
	{
		edge curEdge = EdgeList[i];
		int Start = get<0>(curEdge);
		int End = get<1>(curEdge);
		int Time = get<2>(curEdge);

		if (Shortest[Start] != LONG_MAX &&
			Shortest[End] > Shortest[Start] + Time)
		{
			IsMinusLoop = true;
		}
	}
}