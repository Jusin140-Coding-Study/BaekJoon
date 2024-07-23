/*
* @title    : 11404번 플로이드(골드4)
* @content  : 플로이드-워셜
* @author   : 손동찬
* @date     : 240723
* @time     : 24 ms
* @memory   : 2152 KB
* @state    : 완료
*/
#include <iostream>
#include <vector>

using namespace std;

#define INF 10000000001

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	vector<vector<long long>> vecDatas(N + 1, vector<long long>(N + 1, INF));

	for (int i = 1; i <= N; ++i)
		vecDatas[i][i] = 0;

	for (int i = 0; i < M; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if(vecDatas[a][b] > c)
			vecDatas[a][b] = c;
	}

	for (int K = 1; K <= N; ++K)
		for (int S = 1; S <= N; ++S)
			for (int E = 1; E <= N; ++E)
				vecDatas[S][E] = min(vecDatas[S][E], vecDatas[S][K] + vecDatas[K][E]);

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			if(vecDatas[i][j] == INF)
				cout << "0 ";
			else
				cout << vecDatas[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}
