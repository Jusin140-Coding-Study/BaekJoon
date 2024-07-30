#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int Find(int a);
void Union(int a, int b);
static vector<int> Parents;

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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int V = 0; int E = 0;
	cin >> V >> E;
	
	priority_queue<Edge, vector<Edge>, greater<Edge>> pQ;
	Parents = vector<int>(V + 1, 0);

	for (int i = 1; i <= V; ++i)
		Parents[i] = i;

	for (int i = 0; i < E; ++i)
	{
		int s = 0;
		int e = 0;
		int v = 0;

		cin >> s >> e >> v;
		pQ.push(Edge{ s, e, v });
	}

	int useEdge = 0;
	int result = 0;

	while (useEdge < V - 1)
	{
		Edge now = pQ.top();
		pQ.pop();

		if (Find(now.s) != Find(now.e))
		{
			Union(now.s, now.e);
			result = result + now.v;
			++useEdge;
		}
	}

	cout << result << "\n";

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
	if (Parents[a] == a)
		return a;
	else
		return Parents[a] = Find(Parents[a]);
}