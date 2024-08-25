#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct edge
{
	int start	= -1;
	int end		= -1;
	int weight	= 0;

	bool operator > (const edge& _other) const
	{
		return weight > _other.weight;
	}
};

static priority_queue<edge, vector<edge>, greater<edge>> pQ;
static vector<int> parent;
void unionfunc(int a, int b);
int find(int a);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int V = 0; int E = 0; int Result = 0;
	cin >> V >> E;

	parent = vector<int>(V + 1, 0);

	for (int i = 1; i <= V; ++i)
		parent[i] = i;

	for (int i = 0; i < E; ++i)
	{
		int start, end, weight;
		cin >> start >> end >> weight;

		pQ.push(edge{ start, end, weight });
	}

	int linkedNodeNum = 0;

	while (linkedNodeNum < V - 1)
	{
		edge curEdge = pQ.top();
		pQ.pop();

		if (find(curEdge.start) != find(curEdge.end))
		{
			unionfunc(curEdge.start, curEdge.end);
			Result += curEdge.weight;
			linkedNodeNum++;
		}
	}

	cout << Result;
}

void unionfunc(int a, int b)
{
	a = find(a);
	b = find(b);

	if (a != b)
		parent[b] = a;
}

int find(int a)
{
	if (a == parent[a])
		return a;
	else
		return parent[a] = find(parent[a]);
}