#include <iostream>
#include <algorithm>
using namespace std;

static long DP[100001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0; int Max = 0; int Term = 0;
	cin >> N;

	cin >> DP[1];
	Max = DP[1];
	for (int i = 2; i <= N; ++i)
	{
		int Input = 0;
		cin >> Input;

		DP[i] = DP[i - 1] + Input;

		if (DP[i] > Max)
			Max = DP[i];
		else
		{
			Max
		}
	}

	cout << Max << "\n";

	return 0;
}