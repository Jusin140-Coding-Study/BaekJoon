/*
* @title    : 2751번 수 정렬하기 2(실버5)
* @content  : 병합정렬
* @author   : 손동찬
* @date     : 240712
* @time     : 288 ms
* @memory   : 9836 KB
* @state    : 완료
*/
#include <iostream>
#include <vector>

using namespace std;

void MergeSort(vector<int> &_vec, vector<int>& _vecTemp, int _FrontIndex, int _BackIndex);

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
    
    MergeSort(v, vTemp, 0, N-1);

    for(int& num : v)
        cout << num << "\n";

    return 0;
}

void MergeSort(vector<int>& _vec, vector<int>& _vecTemp, int _FrontIndex, int _BackIndex)
{
    if (_FrontIndex >= _BackIndex) return;

    int iPartition = (_FrontIndex + _BackIndex) / 2;

    MergeSort(_vec, _vecTemp, _FrontIndex, iPartition);
    MergeSort(_vec, _vecTemp, iPartition +1 ,_BackIndex);

    for (int i = _FrontIndex; i <= _BackIndex; ++i)
        _vecTemp[i] = _vec[i];

    int iIndexA = _FrontIndex;
    int iIndexB = iPartition + 1;
    int iIndexCount = _FrontIndex;
    while (iIndexA <= iPartition && iIndexB <= _BackIndex)
    {
        if (_vecTemp[iIndexA] < _vecTemp[iIndexB])
            _vec[iIndexCount++] = _vecTemp[iIndexA++];
        else
            _vec[iIndexCount++] = _vecTemp[iIndexB++];
    }

    while (iIndexA <= iPartition)
        _vec[iIndexCount++] = _vecTemp[iIndexA++];
    

    while (iIndexB <= _BackIndex)
        _vec[iIndexCount++] = _vecTemp[iIndexB++];
}
