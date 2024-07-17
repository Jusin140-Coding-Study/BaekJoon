#include <iostream>
#include <vector>
using namespace std;

// quick sort
void QuickSort(vector<int>& _vecInput, int _iStart, int _iEnd, int _iK)
{
	if (_iStart >= _iEnd) return;

	else if (1 == _iEnd - _iStart)
	{
		if (_vecInput[_iStart] > _vecInput[_iEnd])
		{
			int iTemp = _vecInput[_iStart];
			_vecInput[_iStart] = _vecInput[_iEnd];
			_vecInput[_iEnd] = iTemp;
		}

		return;
	}

	int iLeft = _iStart;
	int iRight = _iEnd;
	int iPivot = _vecInput[(_iStart + _iEnd) / 2];

	while (iLeft <= iRight)
	{
		while (_vecInput[iLeft] < iPivot)
		{
			iLeft++;
		}

		while (_vecInput[iRight] > iPivot)
		{
			iRight--;
		}

		if (iLeft <= iRight)
		{
			int iTemp = _vecInput[iLeft];
			_vecInput[iLeft] = _vecInput[iRight];
			_vecInput[iRight] = iTemp;

			iLeft++;
			iRight--;
		}
	}

	if (_iStart < iRight)
		QuickSort(_vecInput, _iStart, iRight, _iK);

	if (iRight == _iK)
		return;

	if (iLeft < _iEnd)
		QuickSort(_vecInput, iLeft, _iEnd, _iK);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iK;
	cin >> iN >> iK;

	vector<int> vecInput(iN, 0);

	for (int i = 0; i < iN; ++i)
	{
		cin >> vecInput[i];
	}

	QuickSort(vecInput, 0, iN - 1, iK);

	cout << vecInput[iK - 1];
}