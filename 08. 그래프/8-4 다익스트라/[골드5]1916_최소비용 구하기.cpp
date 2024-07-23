#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

typedef pair<int, int> edge;
vector<vector<edge>> NearList;
vector<int> Shortest;
vector<bool> Visited;
priority_queue<edge, vector<edge>, greater<edge>> pQ;
void Dijkstra(int Start, int End);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0; int M = 0;
	cin >> N;
	cin >> M;

	// 1. 인접 리스트
	// 2. 최단거리 배열
	// 3. 방문 배열
	NearList = vector<vector<edge>>(N + 1, vector<edge>());
	Shortest = vector<int>(N + 1, INT_MAX);
	Visited = vector<bool>(N + 1, false);

	for (int i = 0; i < M; ++i)
	{
		int u = 0; int v = 0; int w = 0;
		cin >> u >> v >> w;

		NearList[u].push_back(make_pair(v, w));
	}

	int Start = 0; int End = 0;
	cin >> Start >> End;

	Dijkstra(Start, End);

	cout << Shortest[End] << "\n";
}

void Dijkstra(int Start, int End)
{
	pQ.push({ 0, Start });
	Shortest[Start] = 0;

	while (!pQ.empty())
	{
		edge curNode = pQ.top();
		pQ.pop();

		int curIndex = curNode.second;
		if (Visited[curIndex])
			continue;

		Visited[curIndex] = true;
		for (int i = 0; i < NearList[curIndex].size(); ++i)
		{
			edge nextNode = NearList[curIndex][i];

			int nextIndex = nextNode.first;
			int weight = nextNode.second;

			if (Shortest[nextIndex] > Shortest[curIndex] + weight)
			{
				Shortest[nextIndex] = Shortest[curIndex] + weight;
				pQ.push(make_pair(Shortest[nextIndex], nextIndex));
			}
		}
	}
}