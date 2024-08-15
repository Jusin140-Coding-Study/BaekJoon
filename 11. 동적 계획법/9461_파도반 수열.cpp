#include <iostream>
using namespace std;

static long DP[101];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int CaseCnt = 0;
	cin >> CaseCnt;

	DP[1] = 1;
	DP[2] = 1;
	DP[3] = 1;

	for (int i = 4; i <= 100; ++i)
		DP[i] = DP[i - 3] + DP[i - 2];

	for (int i = 0; i < CaseCnt; ++i)
	{
		int Input = 0;
		cin >> Input;

		cout << DP[Input] << "\n";
	}

	return 0;
}