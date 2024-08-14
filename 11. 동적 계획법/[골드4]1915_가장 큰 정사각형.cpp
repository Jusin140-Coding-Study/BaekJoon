#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0; int M = 0;
	int Max = 0;
	cin >> N >> M;

	vector<vector<int>> Arr = vector<vector<int>>(N, vector<int>(M, 0));
	vector<vector<int>> DP = vector<vector<int>>(N, vector<int>(M, 0));
	for (int i = 0; i < N; ++i)
	{
		string input = "";
		cin >> input;

		for (int j = 0; j < input.size(); ++j)
		{
			Arr[i][j] = input[j] - '0';
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			DP[i][j] = Arr[i][j];

			if (Arr[i][j] && 0 < i && 0 < j)
			{
				if(Arr[i][j - 1] && Arr[i - 1][j] && Arr[i - 1][j - 1])
					DP[i][j] = min(DP[i - 1][j - 1], min(DP[i][j - 1], DP[i - 1][j])) + 1;
			}

			if (DP[i][j] > Max)
				Max = DP[i][j];
		}
	}

	cout << Max * Max;

	return 0;
}