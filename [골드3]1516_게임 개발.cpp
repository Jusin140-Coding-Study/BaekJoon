#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;
	cin >> N;

	vector<int> BuildTime(N + 1, 0);
	vector<int> InDegree(N + 1, 0);
	vector<vector<int>> NearList(N + 1, vector<int>());

	for (int i = 1; i <= N; ++i)
	{
		cin >> BuildTime[i];

		int Input = 0;
		while (-1 != Input)
		{
			cin >> Input;
			if (-1 == Input) break;

			NearList[Input].push_back(i);
			InDegree[i]++;
		}
	}

	queue<int> Q;
	int StartIndex = 0;
	for (int i = 1; i <= N; ++i)
	{
		if (0 == InDegree[i])
			Q.push(i);
	}

	vector<int> Result(N + 1, 0);

	while (!Q.empty())
	{
		int curNode = Q.front();
		Q.pop();

		for (int j = 0; j < NearList[curNode].size(); ++j)
		{
			int nextNode = NearList[curNode][j];
			InDegree[nextNode]--;

			Result[nextNode] = max(Result[nextNode], Result[curNode] + BuildTime[curNode]);

			if (0 == InDegree[nextNode])
				Q.push(nextNode);
		}
	}

	for (int i = 1; i <= N; ++i)
		cout << Result[i] + BuildTime[i] << "\n";
}