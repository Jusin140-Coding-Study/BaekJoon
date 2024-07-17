#include <iostream>
#include <vector>
using namespace std;

void MergeSort(vector<int>& _vecInput, vector<int>& _vecResult, int _iFront, int _iBack)
{
    if (_iBack - _iFront > 1)
    {
        vector<int> vecSort(_vecInput.size(), 0);

        int iSize = (_iFront + _iBack) / 2 - _iFront;

        if (iSize == 0)
            vecSort[_iFront] = _vecInput[_iFront];
        else if (iSize == 1)
        {
            if (_vecInput[(_iFront + _iBack) / 2] < _vecInput[_iFront])
            {
                vecSort[_iFront] = _vecInput[(_iFront + _iBack) / 2];
                vecSort[(_iFront + _iBack) / 2] = _vecInput[_iFront];
            }
            else
            {
                vecSort[_iFront] = _vecInput[_iFront];
                vecSort[(_iFront + _iBack) / 2] = _vecInput[(_iFront + _iBack) / 2];
            }
        }
        else
            MergeSort(_vecInput, vecSort, _iFront, (_iFront + _iBack) / 2);

        iSize = _iBack - ((_iFront + _iBack) / 2 + 1);

        if (iSize == 0)
            vecSort[_iBack] = _vecInput[_iBack];
        else if (iSize == 1)
        {
            if (_vecInput[_iBack] < _vecInput[(_iFront + _iBack) / 2 + 1])
            {
                vecSort[(_iFront + _iBack) / 2 + 1] = _vecInput[_iBack];
                vecSort[_iBack] = _vecInput[(_iFront + _iBack) / 2 + 1];
            }
            else
            {
                vecSort[(_iFront + _iBack) / 2 + 1] = _vecInput[_iFront];
                vecSort[_iBack] = _vecInput[(_iFront + _iBack) / 2 + 1];
            }
        }
        else
            MergeSort(_vecInput, vecSort, (_iFront + _iBack) / 2 + 1, _iBack);

        int iFront = _iFront;
        int iBack = (_iFront + _iBack) / 2 + 1;

        int iResultIdx = _iFront;
        bool isGroupLDone = false;
        bool isGroupRDone = false;


        while (iResultIdx <= _iBack)
        {
            if (!isGroupRDone && (vecSort[iFront] > vecSort[iBack]) || isGroupLDone)
            {
                _vecResult[iResultIdx++] = vecSort[iBack++];

                if (iBack > _iBack)
                    isGroupRDone = true;
            }

            else
            {
                _vecResult[iResultIdx++] = vecSort[iFront++];

                if (iFront >= _iBack)
                    isGroupLDone = true;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int iN;
    cin >> iN;

    vector<int> vecInput(iN, 0);
    vector<int> vecResult(iN, 0);

    for (int i = 0; i < iN; ++i)
        cin >> vecInput[i];

    int iFront = 0;
    int iBack = iN - 1;

    if (iN <= 1)
    {
        cout << vecInput[0] << 'n';
        return 0;
    }

    MergeSort(vecInput, vecResult, iFront, iBack);

    for (int i = 0; i < iN; ++i)
        cout << vecResult[i] << '\n';
}