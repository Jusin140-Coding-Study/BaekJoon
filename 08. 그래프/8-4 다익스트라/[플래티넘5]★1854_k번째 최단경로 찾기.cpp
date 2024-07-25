#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

typedef pair<int, int> edge;
vector<vector<edge>> NearList;
vector<priority_queue<int>> Shortest;
priority_queue<edge, vector<edge>, greater<edge>> pQ;
void Dijkstra(int Start, int K);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0; int M = 0; int K = 0;
	cin >> N >> M >> K;

	// 1. 인접 리스트
	// 2. 최단거리 배열
	NearList = vector<vector<edge>>(N + 1, vector<edge>());
	Shortest = vector<priority_queue<int>>(N + 1, priority_queue<int>());

	for (int i = 0; i < M; ++i)
	{
		int u = 0; int v = 0; int w = 0;
		cin >> u >> v >> w;

		NearList[u].push_back(make_pair(v, w));
	}

	Dijkstra(1, K);

	for (int i = 1; i <= N; ++i)
	{
		if (Shortest[i].size() < K)
			cout << -1 << "\n";
		else
			cout << Shortest[i].top() << "\n";
	}
}

void Dijkstra(int Start, int K)
{
	pQ.push(make_pair(0, Start));
	Shortest[Start].push(0);

	while (!pQ.empty())
	{
		edge curNode = pQ.top();
		pQ.pop();

		int curIndex = curNode.second;
		int cost = curNode.first;
		for (int i = 0; i < NearList[curIndex].size(); ++i)
		{
			edge nextNode = NearList[curIndex][i];

			int nextIndex = nextNode.first;
			int weight = nextNode.second;

			if (Shortest[nextIndex].size() < K)
			{
				Shortest[nextIndex].push(cost + weight);

				pQ.push(make_pair(cost + weight, nextIndex));
			}
			else if (Shortest[nextIndex].top() > cost + weight)
			{
				Shortest[nextIndex].pop();
				Shortest[nextIndex].push(cost + weight);

				pQ.push(make_pair(cost + weight, nextIndex));
			}
		}
	}
}