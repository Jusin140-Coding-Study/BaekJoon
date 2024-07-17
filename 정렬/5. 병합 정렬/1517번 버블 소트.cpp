#include <iostream>
#include <vector>
using namespace std;

void MergeSort(vector<int>& _vecNums, vector<int>& _vecSort, int _iFront, int _iBack, int& _iResult)
{
    if (_iFront == _iBack)
        return;

    int iPivot = (_iFront + _iBack) / 2;

    MergeSort(_vecNums, _vecSort, _iFront, iPivot, _iResult);
    MergeSort(_vecNums, _vecSort, iPivot + 1, _iBack, _iResult);

    for (int i = _iFront; i <= _iBack; ++i)
    {
        _vecSort[i] = _vecNums[i];
    }

    int iPoint1 = _iFront;
    int iPoint2 = iPivot + 1;

    int iResultIdx = _iFront;

    bool isGroupLDone = false;
    bool isGroupRDone = false;

    while (iPoint1 <= iPivot && iPoint2 <= _iBack)
    {
        if (_vecSort[iPoint1] > _vecSort[iPoint2])
        {
            _vecNums[iResultIdx++] = _vecSort[iPoint2++];
            _iResult += (iPivot - iPoint1 + 1);
        }
        else
        {
            _vecNums[iResultIdx++] = _vecSort[iPoint1++];
        }
    }

    while (iPoint1 <= iPivot)
        _vecNums[iResultIdx++] = _vecSort[iPoint1++];
    while (iPoint2 <= _iBack)
        _vecNums[iResultIdx++] = _vecSort[iPoint2++];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int iN;
    cin >> iN;

    long iResult = 0;

    vector<int> vecNums(iN, 0);
    vector<int> vecSort(iN, 0);

    for (int i = 0; i < iN; ++i)
        cin >> vecNums[i];

    int iFront = 0;
    int iBack = iN - 1;

    MergeSort(vecNums, vecSort, iFront, iBack, iResult);

    cout << iResult << '\n';
}