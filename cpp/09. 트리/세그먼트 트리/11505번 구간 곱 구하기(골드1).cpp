/*
* @title    : 11505번 구간 곱 구하기(골드1)
* @content  : 세그먼트 트리
* @author   : 손동찬
* @date     : 240730
* @time     : 116 ms
* @memory   : 10404 KB
* @state    : 완료
*/
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

#define DN 1000000007

void SetSgTree(int _iIndex, vector<int>& _vecSgTree)
{
	while (_iIndex > 0)
	{
		_vecSgTree[_iIndex] = (long long)_vecSgTree[_iIndex * 2] * _vecSgTree[_iIndex * 2 + 1] % DN;
		--_iIndex;
	}
}
void ChangeSgTree(int _iIndex, int _iNum, vector<int>& _vecSgTree)
{
	_vecSgTree[_iIndex] = _iNum;

	while (_iIndex > 1)
	{
		if (_iIndex % 2)
			_vecSgTree[_iIndex / 2] = (long long)_vecSgTree[_iIndex] * _vecSgTree[_iIndex - 1] % DN;
		else
			_vecSgTree[_iIndex / 2] = (long long)_vecSgTree[_iIndex] * _vecSgTree[_iIndex + 1] % DN;

		_iIndex /= 2;
	}
}
int MulSgTree(int _iStart, int _iEnd, vector<int>& _vecSgTree)
{
	int iResult = 1;

	while (_iStart <= _iEnd)
	{
		if (_iStart % 2) iResult = (long long)iResult * _vecSgTree[_iStart] % DN;
		if(!(_iEnd % 2)) iResult = (long long)iResult * _vecSgTree[_iEnd] % DN;

		_iStart = (_iStart + 1) / 2;
		_iEnd = (_iEnd - 1) / 2;
	}

	return iResult;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, K;
	cin >> N >> M >> K;

	int P = 1;
	while (pow(2, P) < N)  ++P;
	int iStartIndex = pow(2, P);
	vector<int> vecSgTree(iStartIndex * 2);

	for (int i = 0; i < N; ++i)
		cin >> vecSgTree[iStartIndex + i];
	SetSgTree(iStartIndex - 1, vecSgTree);

	for (int i = 0; i < M + K; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;

		if (a == 1)
			ChangeSgTree(iStartIndex + b - 1, c, vecSgTree);
		else
			cout << MulSgTree(iStartIndex + b - 1, iStartIndex +c - 1, vecSgTree) << "\n";
	}

	return 0;
}
