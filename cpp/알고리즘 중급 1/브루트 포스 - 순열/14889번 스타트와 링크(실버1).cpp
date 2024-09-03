/*
* @title    : 14889번 스타트와 링크(실버1)
* @content  : 브루트 포스 - 순열
* @author   : 손동찬
* @date     : 240824
* @time     : 124 ms
* @memory   : 2020 KB
* @state    : 완료
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<vector<int>> vecDatas(N, vector<int>(N));
	vector<int> vecTeams(N, 0);

	for (int i = N / 2; i < N; ++i)
		vecTeams[i] = 1;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> vecDatas[i][j];

	int Result = 20001;

	while (1)
	{
		int StartTeam = 0, LinkTeam = 0;

		for (int i = 0; i < N-1; ++i)
		{
			for (int j = i+1; j < N; ++j)
			{
				if (vecTeams[i] == vecTeams[j])
				{
					if (vecTeams[i] == 0)
						StartTeam += vecDatas[i][j] + vecDatas[j][i];
					else
						LinkTeam += vecDatas[i][j] + vecDatas[j][i];
				}
			}
		}

		Result = min(Result, abs(StartTeam - LinkTeam));

		if (!next_permutation(vecTeams.begin(), vecTeams.end()))
			break;
	}

	cout << Result;

	return 0;
}
