#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;

vector<int> DP;
vector<int> Input;

int solve(int iIndex)
{
	int& ret = DP[iIndex];

	if (-1 != ret)
		return ret;

	ret = 1;

	for (int i = iIndex + 1; i < N; ++i)
	{
		if (Input[iIndex] < Input[i])
			ret = max(ret, solve(i) + 1);
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int Result = 0;
	cin >> N;

	DP = vector<int>(N, -1);
	Input = vector<int>(N, 0);

	for (int i = 0; i < N; ++i)
		cin >> Input[i];

	for (int i = 0; i < N; ++i)
		Result = max(Result, solve(i));

	cout << Result;

	return 0;
}