/*
* @title    : 1904번 01타일(실버3)
* @content  : 동적 계획법 1
* @author   : 손동찬
* @date     : 240807
* @time     : 4 ms
* @memory   : 5928 KB
* @state    : 완료
*/
#include <iostream>
#include <vector>

using namespace std;

#define MOD 15746

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	cin >> N;

	vector<int> DP(N + 1);
	DP[1] = 1;
	DP[2] = 2;

	for (int i = 3; i <= N; ++i)
		DP[i] = (DP[i - 1] + DP[i - 2]) % MOD;

	cout << DP[N];

	return 0;
}
