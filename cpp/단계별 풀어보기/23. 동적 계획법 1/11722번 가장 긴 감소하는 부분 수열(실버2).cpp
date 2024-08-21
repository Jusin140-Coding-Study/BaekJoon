/*
* @title    : 11722번 가장 긴 감소하는 부분 수열(실버2)
* @content  : 동적 계획법 1
* @author   : 손동찬
* @date     : 240820
* @time     : 0ms
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
	vector<int> Datas(N);
	vector<int> DP(N, 1);

	for (int i = 0; i < N; ++i)
		cin >> Datas[i];

	for (int i = 1; i < N; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (Datas[i] >= Datas[j])
				continue;

			DP[i] = max(DP[i], DP[j] + 1);
		}
	}

	cout << *max_element(DP.begin(), DP.end());

	return 0;
}
