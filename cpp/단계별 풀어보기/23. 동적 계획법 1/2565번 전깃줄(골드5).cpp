/*
* @title    : 2565번 전깃줄(골드5)
* @content  : 동적 계획법 1
* @author   : 손동찬
* @date     : 240821
* @time     : 0ms
* @memory   : 2024 KB
* @state    : 완료
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

typedef pair<int, int> Data;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	cin >> N;
	vector<Data> Datas(N);
	vector<int> DP(N, 1);

	for (int i = 0; i < N; ++i)
		cin >> Datas[i].first >> Datas[i].second;

	sort(Datas.begin(), Datas.end());

	for (int i = 1; i < N; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (Datas[i].second > Datas[j].second)
				DP[i] = max(DP[i], DP[j] + 1);
		}
	}

	int A = 0;
	for (int i = 0; i < N; ++i)
		A = max(A, DP[i]);

	cout << N - A;

	return 0;
}
