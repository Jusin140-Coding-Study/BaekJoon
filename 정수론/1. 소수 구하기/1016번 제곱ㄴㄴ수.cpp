#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long iMin, iMax;
    cin >> iMin >> iMax;

    int iCnt = 0;

    vector<bool> vecPowNN(iMax - iMin + 1, false);

    for (long i = 2; i * i <= iMax; ++i)
    {
        long iPow = i * i;
        long iIdx = iMin / iPow;

        if (iMin % iPow != 0)
            iIdx++;

        for (long j = iIdx; j * iPow <= iMax; ++j)
        {
            vecPowNN[(j * iPow) - iMin] = true;
        }
    }

    for (int i = 0; i <= iMax - iMin; ++i)
    {
        if (!vecPowNN[i])
            iCnt++;
    }

    cout << iCnt;
}