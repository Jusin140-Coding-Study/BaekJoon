#include <iostream>
using namespace std;

static long mod = 15746;
static long DP[1000001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;
	cin >> N;

	DP[1] = 1;
	DP[2] = 2;

	for (int i = 3; i <= 1000000; ++i)
		DP[i] = (DP[i - 2] + DP[i - 1]) % mod;

	cout << DP[N] << "\n";

	return 0;
}