#include <iostream>
using namespace std;

void RemoveCurDNA(int _iIdx, string& _strDNA, int* _iDNACnt)
{
    switch (_strDNA[_iIdx])
    {
    case 'A':
        _iDNACnt[0]++;
        break;
    case 'C':
        _iDNACnt[1]++;
        break;
    case 'G':
        _iDNACnt[2]++;
        break;
    case 'T':
        _iDNACnt[3]++;
        break;
    }
}

void AddCurDNA(int _iIdx, string& _strDNA, int* _iDNACnt)
{
    switch (_strDNA[_iIdx])
    {
    case 'A':
        _iDNACnt[0]--;
        break;
    case 'C':
        _iDNACnt[1]--;
        break;
    case 'G':
        _iDNACnt[2]--;
        break;
    case 'T':
        _iDNACnt[3]--;
        break;
    }
}

bool CheckCurDNA(int _iIdx, string& _strDNA, int _iPartLength, int* _iDNACnt)
{
    AddCurDNA(_iIdx, _strDNA, _iDNACnt);

    if (_iIdx >= _iPartLength)
        RemoveCurDNA(_iIdx - _iPartLength, _strDNA, _iDNACnt);

    bool isPossible = true;

    for (int i = 0; i < 4; ++i)
    {
        if (_iDNACnt[i] > 0)
        {
            isPossible = false;
            return isPossible;
        }
    }

    return isPossible;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int iLength = 0, iPartLength = 0;
    int iResult = 0;

    cin >> iLength >> iPartLength;

    string strDNA;
    cin >> strDNA;

    int iDNACnt[4] = {};

    for (int i = 0; i < 4; ++i)
    {
        cin >> iDNACnt[i];
    }
    
    for (int i = 0; i < iPartLength - 1; ++i)
        AddCurDNA(i, strDNA, iDNACnt);

    for (int i = iPartLength - 1; i < iLength; ++i)
    {
        if (CheckCurDNA(i, strDNA, iPartLength, iDNACnt))
            iResult++;
    }

    cout << iResult << "\n";
}