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
	int N = 0; int M = 0; int Result = 0;

	cin >> NumTestCase;

	Combination = vector<vector<int>>(31, vector<int>(31, 0));
	Combination[1][0] = 1;
	Combination[1][1] = 1;

	for (int i = 0; i <= 30; ++i)
		Combination[i][0] = 1;

	MakeCombination(30);

	for (int i = 0; i < NumTestCase; ++i)
	{
		cin >> N >> M;

		cout << Combination[M][N] << "\n";
	}

	return 0;
}

void MakeCombination(int n)
{
	for (int i = 2; i <= n; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			Combination[i][j] = Combination[i - 1][j - 1] + Combination[i - 1][j];
		}
	}
}