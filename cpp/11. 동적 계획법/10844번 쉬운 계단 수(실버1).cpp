/*
* @title    : 10844번 쉬운 계단 수(실버1)
* @content  : 동적 계획법
* @author   : 손동찬
* @date     : 240808
* @time     : 0ms
* @memory   : 2020 KB
* @state    : 완료
*/
#include <iostream>
#include <vector>

using namespace std;

#define MOD 1000000000

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<vector<int>> DP(N + 1, vector<int>(10, 0));

	for (int i = 1; i <= 9; ++i)
		DP[1][i] = 1;
	
	for (int i = 2; i <= N; ++i)
	{
		DP[i][0] = DP[i - 1][1];
		DP[i][9] = DP[i - 1][8];

		for (int j = 1; j < 9; ++j)
			DP[i][j] = (DP[i - 1][j - 1] + DP[i - 1][j + 1]) % MOD;
	}

	int Result = 0;
	for (int i = 0; i <= 9; ++i)
	{
		Result += DP[N][i];
		Result %= MOD;
	}
	cout << Result;

	return 0;
}