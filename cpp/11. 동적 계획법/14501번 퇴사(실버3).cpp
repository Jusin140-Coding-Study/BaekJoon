/*
* @title    : 14501번 퇴사(실버3)
* @content  : 동적 계획법
* @author   : 손동찬
* @date     : 240807
* @time     : 0ms
* @memory   : 2020 KB
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
	vector<vector<pair<int, int>>> vecDatas(N + 1);
	for (int i = 1; i <= N; ++i)
	{
		pair<int, int> p;
		cin >> p.first >> p.second;
		if (i + p.first - 1 > N)
			continue;

		vecDatas[i + p.first - 1].push_back(p);
	}

	vector<int> DP(N + 1, 0);
	for (int i = 1; i <= N; ++i)
	{
		for (auto& p : vecDatas[i])
		{
			if(p.first == 1)
				DP[i] = max(DP[i], DP[i-1] + p.second);

			else 
				DP[i] = max(DP[i], DP[i - p.first] + p.second);
		}

		DP[i] = max(DP[i], DP[i - 1]);
	}

	cout << DP[N];

	return 0;
}