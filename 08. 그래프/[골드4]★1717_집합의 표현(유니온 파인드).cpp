#include <iostream>
#include <vector>
using namespace std;

static vector<int> V;
void Union(int a, int b);
int Find(int a);
bool CheckSame(int a, int b);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0; int m = 0;
	cin >> n >> m;

	V = vector<int>(n + 1, 0);
	for (int i = 0; i <= n; ++i)
		V[i] = i;

	for(int i = 0; i < m; ++i)
	{
		int question = 0;
		cin >> question;

		int a = 0; int b = 0;
		cin >> a >> b;

		// 0 == 합집합
		if (0 == question)
		{
			Union(a, b);
		}
		// 1 == 같은 집합에 포함되어 있는지
		else if(1 == question)
		{
			if (CheckSame(a, b))
				cout << "YES" << "\n";
			else
				cout << "NO" << "\n";
		}
	}
}

void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);

	if (a != b)
		V[b] = a;
}

int Find(int a)
{
	if (a == V[a])
		return a;
	else
		return V[a] = Find(V[a]);
}

bool CheckSame(int a, int b)
{
	a = Find(a);
	b = Find(b);

	if (a == b)
		return true;
	else
		return false;
}