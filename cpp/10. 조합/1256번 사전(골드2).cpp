/*
* @title    : 1256번 사전(골드2)
* @content  : 조합
* @author   : 손동찬
* @date     : 240806
* @time     : 0ms
* @memory   : 2416 KB
* @state    : 완료
*/
#include <iostream>
#include <vector>

using namespace std;

#define MAX 1000000000

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, K;
	cin >> N >> M >> K;
	int Total = N + M;
	vector<vector<long long>> vecDP(Total+1, vector<long long>(Total+1,0));

	for (int i = 0; i <= Total; ++i)
	{
		vecDP[i][0] = 1;
		vecDP[i][1] = i;
		vecDP[i][i] = 1;
	}

	for (int i = 3; i <= Total; ++i)
		for (int j = 2; j < i; ++j)
		{
			vecDP[i][j] = vecDP[i - 1][j] + vecDP[i - 1][j - 1];
			if (vecDP[i][j] > MAX) vecDP[i][j] = MAX+1;
		}
	if (vecDP[Total][M] < K)
	{
		cout << "-1";
		return 0;
	}

	for (int i = 0; i < Total; ++i)
	{
		if (vecDP[N+M-1][M] >= K)
		{
			cout << "a";
			--N;
		}
		else
		{
			cout << "z";
			K -= vecDP[N + M - 1][M];
			--M;
		}
	}

	return 0;
} 