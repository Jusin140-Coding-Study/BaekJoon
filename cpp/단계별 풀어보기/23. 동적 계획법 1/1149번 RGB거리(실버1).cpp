/*
* @title    : 1149번 RGB거리(실버1)
* @content  : 동적 계획법 1
* @author   : 손동찬
* @date     : 240813
* @time     : 0ms
* @memory   : 2164 KB
* @state    : 완료
*/
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	cin >> N;
	vector<vector<int>> vecCost(N + 1, vector<int>(3, 0));
	vector<vector<int>> DP(N + 1, vector<int>(3, 0));

	for (int i = 1; i <= N; ++i)
		cin >> vecCost[i][0] >> vecCost[i][1] >> vecCost[i][2];

	for (int i = 0; i < 3; ++i)
		DP[1][i] = vecCost[1][i];

	for (int i = 2; i <= N; ++i)
	{
		DP[i][0] = min(DP[i - 1][1], DP[i - 1][2]) + vecCost[i][0];
		DP[i][1] = min(DP[i - 1][2], DP[i - 1][0]) + vecCost[i][1];
		DP[i][2] = min(DP[i - 1][0], DP[i - 1][1]) + vecCost[i][2];
	}
	int minCost = 10000001;
	for (int i = 0; i < 3; ++i)
		minCost = min(minCost, DP[N][i]);

	cout << minCost;

	return 0;
}
