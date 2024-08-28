#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool BinarySearch(const vector<int>& _vec, int _iStartIndex, int _iEndIndex, int _iTarget);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0; int M = 0;
	cin >> N;

	vector<int> vecNums = vector<int>(N, 0);
	for (int i = 0; i < N; ++i)
		cin >> vecNums[i];

	sort(vecNums.begin(), vecNums.end());

	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		int iTemp = 0;
		cin >> iTemp;

		cout << BinarySearch(vecNums, 0, N - 1, iTemp) << "\n";
	}


	return 0;
}

bool BinarySearch(const vector<int>& _vec, int _iStartIndex, int _iEndIndex, int _iTarget)
{
	if (_iEndIndex - _iStartIndex <= 1)
	{
		if (_vec[_iStartIndex] == _iTarget || _vec[_iEndIndex] == _iTarget)
			return true;
		else
			return false;
	}

	int iMiddleIndex = (_iStartIndex + _iEndIndex) / 2;
	int iMiddleValue = _vec[(_iStartIndex + _iEndIndex) / 2];
	if (iMiddleValue == _iTarget)
		return true;

	if (_iTarget < iMiddleValue)
		return BinarySearch(_vec, _iStartIndex, iMiddleIndex, _iTarget);
	else
		return BinarySearch(_vec, iMiddleIndex + 1, _iEndIndex, _iTarget);
}