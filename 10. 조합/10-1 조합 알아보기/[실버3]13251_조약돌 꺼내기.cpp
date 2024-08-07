#include <iostream>
#include <vector>
using namespace std;

static vector<int> NumStones;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int M = 0; int K = 0;
	int NumAllStones = 0;
	cin >> M;

	NumStones = vector<int>(M, 0);
	for (int i = 0; i < M; ++i)
	{
		cin >> NumStones[i];
		NumAllStones += NumStones[i];
	}

	cin >> K;

	double Result = 0.0;

	for (int i = 0; i < M; ++i)
	{
		if (K > NumStones[i])
			continue;

		double SumRatio = 1.0;
		int tempNum = NumAllStones;

		for (int j = 0; j < K; ++j)
		{
			SumRatio *= (double)((double)NumStones[i] / (double)tempNum);
			NumStones[i]--;
			tempNum--;
		}

		Result += SumRatio;
	}

	cout.fixed;
	cout.precision(9);
	cout << Result;

	return 0;
}