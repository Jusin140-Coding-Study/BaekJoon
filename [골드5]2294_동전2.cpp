#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static vector<int> Coins;
static vector<int> DP;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	Coins = vector<int>(N, 0);
	for (int i = 0; i < N; i++)
		cin >> Coins[i];

	DP = vector<int>(K + 1, 10001);
	DP[0] = 0;

	for(int i = 0; i < N; ++i)
		for (int j = Coins[i]; j <= K; ++j)
			DP[j] = min(DP[j], DP[j - Coins[i]] + 1);

	if (DP[K] == 10001)
		cout << -1;
	else
		cout << DP[K];

	return 0;
}