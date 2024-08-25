#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

typedef pair<int, int> node;
static vector<vector<node>> nearList;
static vector<bool> visited;
static vector<int> dist;
void BFS(int iStartIndex);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0; int M = 0;
	cin >> N;
	cin >> M;

	nearList = vector<vector<node>>(N + 1, vector<node>());
	visited = vector<bool>(N + 1, false);
	dist = vector<int>(N + 1, INT_MAX);

	for (int i = 0; i < M; ++i)
	{
		int u, v, weight;
		cin >> u >> v >> weight;

		nearList[u].push_back(make_pair(v, weight));
	}

	int start, end;
	cin >> start >> end;

	BFS(start);

	cout << dist[end];
}

void BFS(int iStartIndex)
{
	dist[iStartIndex] = 0;

	priority_queue<node, vector<node>, greater<node>> pQ;
	pQ.push(make_pair(0, iStartIndex));

	while (!pQ.empty())
	{
		node curNode = pQ.top();
		pQ.pop();

		if (visited[curNode.second]) continue;
		visited[curNode.second] = true;

		for (int i = 0; i < nearList[curNode.second].size(); ++i)
		{
			node nextNode = nearList[curNode.second][i];
			int nextIndex = nextNode.first;
			int weight = nextNode.second;

			if (dist[nextIndex] > dist[curNode.second] + weight)
			{
				dist[nextIndex] = dist[curNode.second] + weight;
				pQ.push(make_pair(dist[nextIndex], nextIndex));
			}
		}
	}
}