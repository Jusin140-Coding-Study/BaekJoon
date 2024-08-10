/*
* @title    : 1463번 1로 만들기(실버3)
* @content  : 동적 계획법
* @author   : 손동찬
* @date     : 240807
* @time     : 4 ms
* @memory   : 5928 KB
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
	vector<int> DP(N + 1);

	DP[1] = 0;

	for (int i = 2; i <= N; ++i)
	{
		DP[i] = DP[i - 1] + 1;

		if (!(i % 2))
			DP[i] = min(DP[i], DP[i / 2] + 1);

		if (!(i % 3))
			DP[i] = min(DP[i], DP[i / 3] + 1);
	}

	cout << DP[N];

	return 0;
}