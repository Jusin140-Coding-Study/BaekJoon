/*
* @title    : 18352번 특정 거리의 도시 찾기(실버2)
* @content  : 그래프의 표현
* @author   : 손동찬
* @date     : 240719
* @time     : 416 ms
* @memory   : 22136 KB
* @state    : 완료
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M, K, X;
	cin >> N >> M >> K >> X;
	vector<vector<int>> AdjacencyList(N+1);
	vector<bool> vecCheck(N + 1, false);
	vector<int> vecDistance(N + 1, 0);
	queue<int> queNums;

	for (int i = 0; i < M; ++i)
	{
		int a, b;
		cin >> a >> b;
		AdjacencyList[a].push_back(b);
	}
	queNums.push(X);
	vecDistance[X] = 0;

	while (!queNums.empty())
	{
		int iFront = queNums.front();
		queNums.pop();

		if (vecCheck[iFront])
			continue;

		vecCheck[iFront] = true;

		for (int i = 0; i < AdjacencyList[iFront].size(); ++i)
		{
			if (vecCheck[AdjacencyList[iFront][i]])
				continue;

			queNums.push(AdjacencyList[iFront][i]);

			if(!vecDistance[AdjacencyList[iFront][i]])
				vecDistance[AdjacencyList[iFront][i]] = vecDistance[iFront] + 1;		
		}
	}

	bool None = true;
	for (int i = 1; i <= N; ++i)
		if (vecDistance[i] == K)
		{
			cout << i << "\n";
			None = false;
		}
	
	if (None)cout << "-1";

	return 0;
}
