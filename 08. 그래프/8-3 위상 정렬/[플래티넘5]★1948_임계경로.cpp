#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0; int M = 0;
	cin >> N;
	cin >> M;

	vector<int> InDegree(N + 1, 0);
	vector<vector<pair<int, int>>> NearList(N + 1, vector<pair<int, int>>());
	vector<vector<pair<int, int>>> RNearList(N + 1, vector<pair<int, int>>());

	for (int i = 0; i < M; ++i)
	{
		int Src = 0; int Dst = 0; int Weight = 0;
		cin >> Src >> Dst >> Weight;

		NearList[Src].push_back({ Dst,Weight });
		RNearList[Dst].push_back({ Src, Weight });
		InDegree[Dst]++;
	}

	int Start = 0; int Destination = 0;
	cin >> Start >> Destination;

	queue<int> Q;
	Q.push(Start);

	vector<int> Result = vector<int>(N + 1, 0);

	while (!Q.empty())
	{
		int curNode = Q.front();
		Q.pop();

		for (auto next : NearList[curNode])
		{
			InDegree[next.first]--;
			Result[next.first] = max(Result[next.first], Result[curNode] + next.second);

			if (0 == InDegree[next.first])
				Q.push(next.first);
		}
	}

	// Reverse 위상정렬
	int ResultCnt = 0;
	vector<bool> Visited = vector<bool>(N + 1, false);

	queue<int> rQ;
	rQ.push(Destination);
	Visited[Destination] = true;

	while (!rQ.empty())
	{
		int curNode = rQ.front();
		rQ.pop();

		for (auto next : RNearList[curNode])
		{
			if (Result[next.first] + next.second == Result[curNode])
			{ 
				++ResultCnt;

				if (!Visited[next.first])
				{
					Visited[next.first] = true;
					rQ.push(next.first);
				}
			}
		}
	}

	cout << Result[Destination] << "\n";
	cout << ResultCnt << "\n";
}