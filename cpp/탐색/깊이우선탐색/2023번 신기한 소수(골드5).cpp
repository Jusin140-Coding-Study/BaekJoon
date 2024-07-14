/*
* @title    : 2023번 신기한 소수(골드5)
* @content  : 깊이우선탐색
* @author   : 손동찬
* @date     : 240713
* @time     : 0ms
* @memory   : 2036 KB
* @state    : 완료
*/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isPrimeNumber(int _iNum)
{
    if (_iNum == 2)
        return true;

    if (_iNum <= 1 || !(_iNum & 1))
        return false;
    
    int sqrtNum = sqrt(_iNum);
    for (int i = 3; i <= sqrtNum; i += 2)
    {
        if (_iNum % i == 0)
            return false;       
    }
    return true;
}

void DFS(int _iStartNum, vector<int> _vCheck, int iNumSize, int iCurSize)
{
    if (iCurSize == iNumSize)
    {
        if (isPrimeNumber(_iStartNum))
            cout << _iStartNum << "\n";
        
        return;
    }

    if (isPrimeNumber(_iStartNum))
    {
        int a = iCurSize+1;
        for (int& iter : _vCheck)
            DFS(_iStartNum * 10 + iter, _vCheck, iNumSize, a);
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> vStart = { 2,3,5,7};
    vector<int> vCheck = { 1,3,5,7,9};

    for(int& iter : vStart)
        DFS(iter, vCheck, N, 1);

    return 0;
}