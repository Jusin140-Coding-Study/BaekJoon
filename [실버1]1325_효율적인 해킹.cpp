#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static int MaxHackedCom = 1;
static int HackableComCount = 1;
vector<vector<int>> V;
vector<bool> Visited;
void DFS(int index);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0; int M = 0;
	cin >> N >> M;

	V = vector<vector<int>>(N + 1, vector<int>());
	Visited = vector<bool>(N + 1, false);

	for (int i = 1; i <= M; ++i)
	{
		int A = 0; int B = 0;
		cin >> A >> B;

		V[B].push_back(A);
	}

	vector<int> RIndex;
	for (int i = 1; i <= N; ++i)
	{
		Visited = vector<bool>(N + 1, false);

		HackableComCount = 0;
		DFS(i);
		if (HackableComCount > MaxHackedCom)
		{
			MaxHackedCom = HackableComCount;
			RIndex.clear();
			RIndex.push_back(i);
		}
		else if(HackableComCount == MaxHackedCom)
		{
			RIndex.push_back(i);
		}
	}

	for (const auto& index : RIndex)
		cout << index << " ";
	
	return 0;
}

void DFS(int index)
{
	Visited[index] = true;
	++HackableComCount;

	for (int i = 0; i < V[index].size(); ++i)
	{
		if (!Visited[V[index][i]])
			DFS(V[index][i]);
	}
}