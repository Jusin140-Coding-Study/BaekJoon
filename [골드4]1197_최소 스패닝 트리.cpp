#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct edge
{
	int s = 0; int e = 0; int w = 0;

	bool operator < (const edge& _rhs) const
	{
		return w < _rhs.w;
	}
};

static vector<int> parent;
static vector<edge> edgelist;
int find(int a);
void unionfunc(int a, int b);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long result = 0;
	int n, m;
	cin >> n >> m;

	parent = vector<int>(n + 1, 0);
	edgelist = vector<edge>(m, edge());

	for (int i = 1; i <= n; ++i)
		parent[i] = i;

	for (int i = 0; i < m; ++i)
	{
		int s, e, w;
		cin >> s >> e >> w;

		edgelist[i] = edge{ s, e, w };
	}
	sort(edgelist.begin(), edgelist.end());

	int numlinkedlines = 0;

	while (numlinkedlines < n - 1)
	{
		for (int i = 0; i < m; ++i)
		{
			edge curEdge = edgelist[i];

			if (find(curEdge.s) != find(curEdge.e))
			{
				result += curEdge.w;
				unionfunc(curEdge.s, curEdge.e);
				numlinkedlines++;
				break;
			}
		}
	}

	cout << result << "\n";

	return 0;
}

int find(int a)
{
	if (a == parent[a])
		return a;
	else
		return parent[a] = find(parent[a]);
}

void unionfunc(int a, int b)
{
	a = find(a);
	b = find(b);

	if (a == b) return;

	parent[b] = a;
}