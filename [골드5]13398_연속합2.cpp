#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

static vector<int> NumArray;
static vector<int> LSum;
static vector<int> RSum;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0; int Result = 0;
	cin >> N;

	NumArray = vector<int>(N, 0);
	LSum = vector<int>(N, 0);
	RSum = vector<int>(N, 0);

	for (int i = 0; i < N; ++i)
		cin >> NumArray[i];

	// LSum[i] = i번째 수를 제외한 왼쪽 수들의 합중 최대수
	LSum[0] = NumArray[0];
	Result = NumArray[0];
	for (int i = 1; i < N; ++i)
	{
		LSum[i] = max(LSum[i - 1] + NumArray[i], NumArray[i]);
		Result = max(Result, LSum[i]);
	}

	RSum[N - 1] = NumArray[N - 1];
	for (int i = N - 2; i > 0; --i)
	{
		RSum[i] = max(RSum[i + 1] + NumArray[i], NumArray[i]);
	}

	for (int i = 1; i < N - 1; ++i)
	{
		Result = max(Result, LSum[i - 1] + RSum[i + 1]);
	}

	cout << Result;

	return 0;
}