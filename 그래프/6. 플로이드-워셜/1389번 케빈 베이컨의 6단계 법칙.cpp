#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int iN, iM;
    cin >> iN >> iM;

    int MAX = 10000001;

    vector<vector<long>> vecAdj(iN + 1, vector<long>(iN + 1, 0));
    vector<int> vecKevinBacon(iN + 1, 0);

    int iPerson1, iPerson2;

    for (int i = 1; i <= iN; ++i)
    {
        for (int j = 1; j <= iN; ++j)
        {
            if (i != j)
                vecAdj[i][j] = MAX;
        }
    }

    for (int i = 0; i < iM; ++i)
    {
        cin >> iPerson1 >> iPerson2;

        vecAdj[iPerson1][iPerson2] = 1;
        vecAdj[iPerson2][iPerson1] = 1;
    }

    for (int iFirst = 1; iFirst <= iN; ++iFirst)
    {
        for (int iSecond = 1; iSecond <= iN; ++iSecond)
        {
            for (int iThird = 1; iThird <= iN; ++iThird)
            {
                if (vecAdj[iSecond][iThird] > vecAdj[iSecond][iFirst] + vecAdj[iFirst][iThird])
                {
                    vecAdj[iSecond][iThird] = vecAdj[iSecond][iFirst] + vecAdj[iFirst][iThird];
                }
            }
        }
    }

    int iSum = 0;
    int iMin = MAX;
    int iResult;

    for (int i = 1; i <= iN; ++i)
    {
        iSum = 0;
        for (int j = 1; j <= iN; ++j)
        {
            iSum += vecAdj[i][j];
        }
        if (iMin > iSum)
        {
            iMin = iSum;
            iResult = i;
        }
    }

    cout << iResult;
}