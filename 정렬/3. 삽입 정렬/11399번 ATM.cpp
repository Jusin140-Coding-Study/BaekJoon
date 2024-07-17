#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int iN;
    cin >> iN;

    vector<int> vecTimes(iN, 0);
    vector<int> vecSum(iN + 1, 0);

    int iResult = 0;

    for (int i = 0; i < iN; ++i)
    {
        cin >> vecTimes[i];

        bool isInserted = false;
        int iInsertIdx = 0;
        int iTemp = 0;

        for (int j = 0; j < i; ++j)
        {
            if (vecTimes[j] > vecTimes[i])
            {
                isInserted = true;
                iInsertIdx = j;
                iTemp = vecTimes[i];
                break;
            }
        }

        if (isInserted)
        {
            for (int k = i; k > iInsertIdx; --k)
            {
                vecTimes[k] = vecTimes[k - 1];
            }

            vecTimes[iInsertIdx] = iTemp;
        }
    }

    for (int i = 1; i <= iN; ++i)
    {
        vecSum[i] = vecSum[i - 1] + vecTimes[i - 1];
        iResult += vecSum[i];
    }

    cout << iResult << '\n';
}