/*
* @title    : 11660번 구간 합 구하기 5(실버1)
* @content  :
* @author   : 손동찬
* @date     : 240709
* @time     : 116 ms
* @memory   : 10356 KB
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
	
	int N, M;
	cin >> N >> M;

	vector<vector<int>> v(N + 1, vector<int>(N + 1, 0));
	vector<vector<int>> vSum(N + 1, vector<int>(N + 1, 0));

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			cin >> v[i][j];
			vSum[i][j] = vSum[i - 1][j] + vSum[i][j - 1] + v[i][j] - vSum[i - 1][j - 1];
		}
	}

	for (int i = 0; i < M; ++i)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >>x2 >>y2;

		cout << vSum[x2][y2] - vSum[x1-1][y2] - vSum[x2][y1-1] + vSum[x1 -1][y1 - 1] <<"\n";
	}
}