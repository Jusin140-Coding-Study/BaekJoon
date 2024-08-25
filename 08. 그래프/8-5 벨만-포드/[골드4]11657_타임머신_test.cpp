#include <iostream>
#include <tuple>
#include <vector>
#include <limits.h>
using namespace std;

static int N, M;
static bool IsCycle = false;
typedef tuple<int, int, int> edge;
static vector<edge> edgeList;
static vector<long> dist;
void Belman(int iStartIndex);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	edgeList = vector<edge>(M + 1, edge(0, 0, 0));
	dist = vector<long>(N + 1, LONG_MAX);

	for (int i = 1; i <= M; ++i)
	{
		int start, end, weight;
		cin >> start >> end >> weight;

		edgeList[i] = make_tuple(start, end, weight);
	}

	dist[1] = 0;

	Belman(1);

	if (!IsCycle)
	{
		for (int i = 2; i <= N; ++i)
		{
			if (dist[i] == LONG_MAX)
				cout << -1 << "\n";
			else
				cout << dist[i] << "\n";
		}
	}
	else
	{
		cout << -1 << "\n";
	}
}

void Belman(int iStartIndex)
{
	for (int i = 1; i < N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			edge curEdge = edgeList[j];
			int start	= get<0>(curEdge);
			int end		= get<1>(curEdge);
			int weight	= get<2>(curEdge);

			if (dist[start] != LONG_MAX && dist[end] > dist[start] + weight)
				dist[end] = dist[start] + weight;
		}
	}

	// ΩŒ¿Ã≈¨ ∞ÀªÁ
	for (int j = 0; j <= M; ++j)
	{
		edge curEdge = edgeList[j];
		int start = get<0>(curEdge);
		int end = get<1>(curEdge);
		int weight = get<2>(curEdge);

		if (dist[start] != LONG_MAX && dist[end] > dist[start] + weight)
		{
			IsCycle = true;
			return;
		}
	}
}