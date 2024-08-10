/*
* @title    : 1722번 순열의 순서(골드5)
* @content  : 조합
* @author   : 손동찬
* @date     : 240806
* @time     : 0ms
* @memory   : 2020 KB
* @state    : 완료
*/
#include <iostream>
#include <vector>

using namespace std;

long long Factorial(int _iNUm)
{
	long long llResult = 1;

	while (_iNUm > 1)
	{
		llResult *= _iNUm;
		--_iNUm;
	}
	return llResult;
}

int FindMinNum(int _iSeq, vector<bool>& _vecUsed)
{
	int count = 0;

	for (int i = 1; i < _vecUsed.size(); ++i)
	{
		if (!_vecUsed[i])
		{
			++count;
			if (count == _iSeq)
			{
				_vecUsed[i] = true;
				return i;
			}
		}
	}
}

int CountMinNum(int _iNum, vector<bool>& _vecUsed)
{
	int count = 0;

	for (int i = 1; i < _iNum; ++i)
		if (!_vecUsed[i])
			++count;			

	return count;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, P;
	long long K;
	cin >> N >> P;
	vector<bool> vecUsed(N + 1, false);
	vector<long long> vecPerNums(N);
	for (int i = 0; i < N; ++i)
		vecPerNums[i] = Factorial(N - i);

	if (P & 1)
	{
		cin >> K;		
		for (int i = 0; i < N-1; ++i)
		{
			int cnt = 1;
			while (K > vecPerNums[i + 1] * cnt)
				++cnt;

			cout << FindMinNum(cnt, vecUsed) << " ";

			K -= (vecPerNums[i + 1] * (cnt - 1));
		}
		cout << FindMinNum(1, vecUsed);
		return 0;
	}

	else
	{
		vector<int> vecPer(N);
		for (int i = 0; i < N; ++i)
			cin >> vecPer[i];
		
		long long K = 1;

		for (int i = 0; i < N-1; ++i)
		{
			int iResult = CountMinNum(vecPer[i], vecUsed);
			vecUsed[vecPer[i]] = true;
			if (iResult)
				K += (vecPerNums[i + 1] * iResult);		
		}
		cout << K;
	}

	return 0;
} 