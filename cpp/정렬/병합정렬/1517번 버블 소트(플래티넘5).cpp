/*
* @title    : 1517번 버블 소트(플래티넘5)
* @content  : 병합정렬
* @author   : 손동찬
* @date     : 240712
* @time     : 108 ms
* @memory   : 5932 KB
* @state    : 완료
*/
#include <iostream>
#include <vector>

using namespace std;

void MergeSort(vector<int>& _vec, vector<int>& _vecTemp, int _FrontIndex, int _BackIndex, long long& _iCount);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> v(N, 0);
    vector<int> vTemp(N, 0);
    for (int i = 0; i < N; ++i)
        cin >> v[i];

    long long iCount = 0;
    MergeSort(v, vTemp, 0, N - 1, iCount);

    cout << iCount << "\n";

    return 0;
}

void MergeSort(vector<int>& _vec, vector<int>& _vecTemp, int _FrontIndex, int _BackIndex, long long& _iCount)
{
    if (_FrontIndex >= _BackIndex) return;

    int iPartition = (_FrontIndex + _BackIndex) / 2;

    MergeSort(_vec, _vecTemp, _FrontIndex, iPartition, _iCount);
    MergeSort(_vec, _vecTemp, iPartition + 1, _BackIndex, _iCount);

    for (int i = _FrontIndex; i <= _BackIndex; ++i)
        _vecTemp[i] = _vec[i];

    int iIndexA = _FrontIndex;
    int iIndexB = iPartition + 1;
    int iIndexCount = _FrontIndex;
    while (iIndexA <= iPartition && iIndexB <= _BackIndex)
    {
        if (_vecTemp[iIndexA] > _vecTemp[iIndexB])
        {
            _iCount += (long long)(iIndexB - iIndexCount);
            _vec[iIndexCount++] = _vecTemp[iIndexB++];
        }
                
        else
            _vec[iIndexCount++] = _vecTemp[iIndexA++];
    }

    while (iIndexA <= iPartition)
        _vec[iIndexCount++] = _vecTemp[iIndexA++];


    while (iIndexB <= _BackIndex)
        _vec[iIndexCount++] = _vecTemp[iIndexB++];
}
