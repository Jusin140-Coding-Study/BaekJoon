#include <iostream>
#include <vector>
using namespace std;

static vector<vector<long long>> Combination;
void MakeCombination(int n);

// 순열 : Permutation
// 조합 : Combination
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N; int K;
	cin >> N >> K;
	
	Combination = vector<vector<long long>>(N + 1, vector<long long>(N + 1, 0));
	Combination[1][0] = 1;
	Combination[1][1] = 1;

	MakeCombination(N);

	cout << Combination[N][K];

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
				Combination[i][j] = 1;
				continue;
			}

			Combination[i][j] = (Combination[i - 1][j - 1] + Combination[i - 1][j]) % 10007;
		}
	}
}