/*
* @title    : 11403번 경로 찾기(실버1)
* @content  : 플로이드-워셜
* @author   : 손동찬
* @date     : 240723
* @time     : 4 ms
* @memory   : 2152 KB
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
	vector<vector<int>> vecDatas(N, vector<int>(N));
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> vecDatas[i][j];

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			for (int k = 0; k < N; ++k)
				if (vecDatas[j][i] + vecDatas[i][k] == 2) vecDatas[j][k] = 1;
		
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
			cout << vecDatas[i][j] <<" ";
		cout << "\n";
	}

	return 0;
}
