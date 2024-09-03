/*
* @title    : 14225번 부분수열의 합(실버1)
* @content  : 브루트 포스 - 재귀
* @author   : 손동찬
* @date     : 240825
* @time     : 124 ms
* @memory   : 8296 KB
* @state    : 완료
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> vecChoice;

void Reset(int num)
{
	for(int i = 0; i < N - num; ++i)
		vecChoice[i] = 0;
	for(int i = N - num; i < N; ++i)
		vecChoice[i] = 1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	vector<int> vecNums(N);
	vecChoice.resize(N, 0);
	for (int i = 0; i < N; ++i)
		cin >> vecNums[i];

	vector<int> vecResult;
	for (int i = 1; i <= N; ++i)
	{
		Reset(i);

		while(1)
		{
			int Sum = 0;
			for (int j = 0; j < N; ++j)
				if (vecChoice[j])
					Sum += vecNums[j];

			vecResult.push_back(Sum);

			if (!next_permutation(vecChoice.begin(), vecChoice.end()))
				break;
		}
	}

	sort(vecResult.begin(), vecResult.end());

	int Result = 1;
	
	for (int i = 0; i < vecResult.size(); ++i)
	{
		if (vecResult[i] == Result)
			++Result;
		else if (vecResult[i] < Result)
			continue;
		else
			break;
	}

	cout << Result;

	return 0;
}
