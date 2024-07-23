/*
* @title    : 1389번 케빈 베이컨의 6단계 법칙(실버1)
* @content  : 플로이드-워셜
* @author   : 손동찬
* @date     : 240723
* @time     : 0ms
* @memory   : 2152 KB
* @state    : 완료
*/
#include <iostream>
#include <vector>

using namespace std;

#define INF 5001

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	vector<vector<int>> vecDatas(N + 1, vector<int>(N + 1, INF));

	for (int i = 1; i <= N; ++i)
		vecDatas[i][i] = 0;
		
	for (int i = 0; i < M; ++i)
	{
		int a, b;
		cin >> a >> b;
		vecDatas[a][b] = 1;
		vecDatas[b][a] = 1;
	}

	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			for (int k = 1; k <= N; ++k)
				vecDatas[j][k] = min(vecDatas[j][k], vecDatas[j][i] + vecDatas[i][k]);

	int min =0;
	int minSum = INF;
	for (int i = 1; i <= N; ++i)
	{
		int sum = 0;
		for (int j = 1; j <= N; ++j)
			sum += vecDatas[i][j];
		
		if (minSum > sum)
		{
			minSum = sum;
			min = i;
		}
	}

	cout << min;

	return 0;
}
