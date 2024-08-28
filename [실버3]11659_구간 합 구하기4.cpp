#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N = 0;
int M = 0;
static vector<int> DP;

void Input()
{
	cin >> N >> M;
	DP = vector<int>(N + 1, 0);

	for (int i = 1; i <= N; ++i)
	{
		int iTemp;
		cin >> iTemp;

		DP[i] = DP[i - 1] + iTemp;
	}
}

void Solve()
{
	for (int i = 0; i < M; ++i)
	{
		int L, R;
		cin >> L >> R;

		cout << DP[R] - DP[L - 1] << "\n";
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Input();
	Solve();

	return 0;
}