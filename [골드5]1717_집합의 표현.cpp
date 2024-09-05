#include <iostream>
#include <vector>
using namespace std;

static vector<int> parent;
int find(int a);
void unionfunc(int a, int b);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	parent = vector<int>(n + 1, 0);
	for (int i = 1; i <= n; ++i)
		parent[i] = i;

	for (int i = 0; i < m; ++i)
	{
		int q, a, b;
		cin >> q >> a >> b;

		if (0 == q)
		{
			unionfunc(a, b);
		}
		else if (1 == q)
		{
			if (find(a) == find(b))
				cout << "YES" << "\n";
			else
				cout << "NO" << "\n";
		}
	}

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