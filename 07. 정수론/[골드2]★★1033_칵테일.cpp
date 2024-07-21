#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> RATIO;
vector<vector<pair<int, RATIO>>> V;
vector<long> D;
vector<bool> Visited;
long gcd(long a, long b);
void DFS(int nodeindex);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;
	cin >> N;

	long lcm = 1; // 최소공배수

	V = vector<vector<pair<int, RATIO>>>(N, vector<pair<int, RATIO>>());
	D = vector<long>(10, 0);
	Visited = vector<bool>(N, false);

	for (int i = 0; i < N; ++i)
	{
		int Src = 0;
		int Dst = 0;
		int Left = 0;
		int Right = 0;

		cin >> Src >> Dst >> Left >> Right;

		V[Src].push_back({ Dst, {Left, Right} });
		V[Dst].push_back({ Src, {Right, Left} });

		lcm *= (Left * Right) / gcd(Left, Right);
	}

	D[0] = lcm;
	DFS(0);
	long mgcd = D[0]; // 최대공약수

	for (int i = 1; i < N; ++i)
	{
		mgcd = gcd(mgcd, D[i]);
	}
	for (int i = 0; i < N; ++i)
	{
		cout << D[i] / mgcd << ' ';
	}
		
	return 0;
}

long gcd(long a, long b)
{
	if (b == 0)
	{
		return a;
	}
	else
	{
		return gcd(b, a % b);
	}
}

void DFS(int nodeindex)
{
	Visited[nodeindex] = true;

	for (const auto& node : V[nodeindex])
	{
		int next = node.first;

		if (!Visited[next])
		{
			D[next] = D[nodeindex] * node.second.second * node.second.first;
			DFS(next);
		}
	}
}