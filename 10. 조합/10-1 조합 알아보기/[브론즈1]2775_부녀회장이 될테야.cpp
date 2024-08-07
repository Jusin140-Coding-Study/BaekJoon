#include <iostream>
#include <vector>
using namespace std;

static vector<vector<int>> Combination;
void MakeCombination(int n);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int NumTestCase = 0;
	int K = 0; int N = 0;

	Combination = vector<vector<int>>(15, vector<int>(15, 0));

	for (int i = 0; i <= 14; ++i)
	{
		Combination[i][1] = 1;
		Combination[0][i] = i;
	}

	MakeCombination(14);

	cin >> NumTestCase;

	for (int i = 0; i < NumTestCase; ++i)
	{
		cin >> K >> N;

		cout << Combination[K][N] << "\n";
	}

	return 0;
}

void MakeCombination(int n)
{
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 2; j <= n; ++j)
		{
			Combination[i][j] = Combination[i][j - 1] + Combination[i - 1][j];
		}
	}
}