#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int iN, iM;
    cin >> iN >> iM;

    vector<int>	vecMin(iN, 0);
    vector<int> vecSum(iM, 0);

    int iStart = 0, iCenter = 0, iEnd = 0;
    int iSum = 0, iCnt = 0;

    for (int i = 0; i < iN; ++i)
    {
        cin >> vecMin[i];

        if (iStart < vecMin[i])
            iStart = vecMin[i];

        iEnd += vecMin[i];
    }

    while (iStart <= iEnd)
    {
        iSum = 0;
        iCnt = 0;

        iCenter = (iStart + iEnd) / 2;

        for (int i = 0; i < iN; ++i)
        {
            if (iSum + vecMin[i] > iCenter)
            {
                iCnt++;
                iSum = 0;
            }
            iSum += vecMin[i];
        }

        if (iSum != 0)
            iCnt++;

        if (iCnt > iM)
            iStart = iCenter + 1;

        else
            iEnd = iCenter - 1;
    }

    cout << iStart;
}