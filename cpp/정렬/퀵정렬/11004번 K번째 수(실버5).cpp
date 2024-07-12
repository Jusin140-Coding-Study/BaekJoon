/*
* @title    : 11004번 K번째 수(실버5)
* @content  : 퀵정렬
* @author   : 손동찬
* @date     : 240712
* @time     : 652 ms
* @memory   : 21552 KB
* @state    : 완료
*/
#include <iostream>
#include <vector>

using namespace std;

void QuickSort(vector<int>& _vec, int _k, int _LeftIndex, int _RightIndex);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;
    vector<int> v(N,0);
    for (int i = 0; i < N; ++i)
        cin >> v[i];

    QuickSort(v, K-1, 0, v.size()-1);

    cout << v[K-1];

    return 0;
}

void QuickSort(vector<int> &_vec, int _k, int _LeftIndex, int _RightIndex)
{
    if (_LeftIndex >= _RightIndex) return;
    
    if (_LeftIndex + 1 == _RightIndex)
    {
        if (_vec[_LeftIndex] > _vec[_RightIndex])
            swap(_vec[_LeftIndex], _vec[_RightIndex]);

        return;
    }

    int iPivotIndex = (_LeftIndex + _RightIndex ) / 2;
    int iPivot = _vec[iPivotIndex];
    swap(_vec[iPivotIndex], _vec[_LeftIndex]);

    int iFront = _LeftIndex + 1;
    int iBack = _RightIndex;

    while (iFront < iBack)
    {
        while (_vec[iBack]  > iPivot && iFront < iBack) iBack--;
        while (_vec[iFront] < iPivot && iFront < iBack) iFront++;

        if (iFront < iBack) {
            swap(_vec[iFront++], _vec[iBack--]);
        }
        else
            break;
    }

    if (iPivot <= _vec[iFront]) 
        iFront--;

    _vec[_LeftIndex] = _vec[iFront];
    _vec[iFront] = iPivot;

    if (iFront == _k)
        return;

    else if (_k < iFront)
        QuickSort(_vec, _k, _LeftIndex, iFront - 1);

    else
        QuickSort(_vec, _k, iFront + 1, _RightIndex);
}
