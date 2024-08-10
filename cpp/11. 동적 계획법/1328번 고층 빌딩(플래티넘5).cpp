/*
* @title    : 1328번 고층 빌딩(플래티넘5)
* @content  : 동적 계획법
* @author   : 손동찬
* @date     : 240809
* @time     : 8 ms
* @memory   : 10472 KB
* @state    : 완료
*/
#include <iostream>
#include <vector>

using namespace std;

#define MOD 1000000007

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N, L, R;
	cin >> N >> L >> R;
	vector<vector<vector<long long>>> DP(N + 1, vector<vector<long long>>(L + 1, vector<long long>(R + 1, 0)));

	DP[1][1][1] = 1;
	for (int i = 2; i <= N; ++i)
		for (int j = 1; j <= L; ++j)
			for (int k = 1; k <= R; ++k)
				DP[i][j][k] = (DP[i - 1][j - 1][k]
							+ DP[i - 1][j][k - 1]
							+ DP[i - 1][j][k] * (i - 2)) % MOD;

	cout << DP[N][L][R];

	return 0;
}