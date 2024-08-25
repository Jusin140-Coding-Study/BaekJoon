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

	int V = 0; int E = 0; int startIndex = 0;
	cin >> V >> E;
	cin >> startIndex;

	nearList = vector<vector<node>>(V + 1, vector<node>());
	visited = vector<bool>(V + 1, false);
	dist = vector<int>(V + 1, INT_MAX);

	for (int i = 0; i < E; ++i)
	{
		int start, end, weight;
		cin >> start >> end >> weight;

		node inputNode;
		inputNode.first = end;
		inputNode.second = weight;

		nearList[start].push_back(inputNode);
	}

	BFS(startIndex);

	for (int i = 1; i <= V; ++i)
	{
		if (INT_MAX == dist[i])
			cout << "INF" << "\n";
		else
			cout << dist[i] << "\n";
	}
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
			node nextNode	= nearList[curNode.second][i];
			int nextIndex	= nextNode.first;
			int weight		= nextNode.second;

			if (dist[nextIndex] > dist[curNode.second] + weight)
			{
				dist[nextIndex] = dist[curNode.second] + weight;
				pQ.push(make_pair(dist[curNode.second] + weight, nextIndex));
			}
		}
	}
}