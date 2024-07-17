#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long iN, iK;
    cin >> iN >> iK;

    long long iStart, iCenter, iEnd;
    long long iResult = 0;

    iStart = 1;
    iEnd = iK;

    long long iLessEqual = 0;

    while (iStart <= iEnd)
    {
        iLessEqual = 0;
        iCenter = (iStart + iEnd) / 2;

        for (int i = 1; i <= iN; ++i)
        {
            iLessEqual += min(iCenter / i, iN);
        }

        if (iLessEqual < iK)
        {
            iStart = iCenter + 1;
        }

        else
        {
            iEnd = iCenter - 1;
            iResult = iCenter;
        }
    }

    cout << iResult;
}