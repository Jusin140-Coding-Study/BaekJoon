#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

static vector<vector<long long>> Combination;
void MakeCombination(int n);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0; int M = 0; int K = 0;
	cin >> N >> M >> K;

	Combination = vector<vector<long long>>(N + M + 1, vector<long long>(N + M + 1));
	Combination[0][0] = 1;
	Combination[1][1] = 1;
	Combination[1][0] = 1;

	MakeCombination(N + M);

	if (Combination[N + M][M] < K)
		cout << -1;
	else
	{
		while (!(N == 0 && M == 0))
		{
			if (K <= Combination[N + M - 1][M])
			{
				cout << 'a';
				--N;
			}
			else
			{
				cout << 'z';
				K = K - Combination[N + M - 1][M];
				--M;
			}
		}
	}

	return 0;
}

void MakeCombination(int n)
{
	for (int i = 2; i <= n; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			if (0 == j)
			{
				Combination[i][0] = 1;
				continue;
			}

			Combination[i][j] = Combination[i - 1][j - 1] + Combination[i - 1][j];
			if (Combination[i][j] > 1000000000)
				Combination[i][j] = 1000000000;
		}
	}
}