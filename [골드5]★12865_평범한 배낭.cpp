#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> DP;
vector<int> w;
vector<int> v;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// N : 물건 개수, K : 준서가 버틸 수 있는 무게
	int N, K;
	cin >> N >> K;

	w = vector<int>(N + 1);
	v = vector<int>(N + 1);

	// DP[i][j] : i개 까지 물건을 담았을 경우, 담을 수 있는 배낭의 무게가 j일 때의 최대 기대값
	DP = vector<vector<int>>(N + 1, vector<int>(K + 1, 0));

	for (int i = 1; i <= N; ++i)
		cin >> w[i] >> v[i];

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= K; ++j)
		{
			// i번째 물건이 담을 수 있는 무게일 경우
			// 1. 물건을 담지 않는 경우, 이전 물건까지 담았을 경우의 최대 기대값과 같음
			// 2. 물건을 담았을 때, 이 물건의 무게를 뺀 무게에서의 최대 기대값에 물건의 무게를 더한 값
			if (j >= w[i])
				DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - w[i]] + v[i]);
			else
				DP[i][j] = DP[i - 1][j];
		}
	}

	cout << DP[N][K];

	return 0;
}