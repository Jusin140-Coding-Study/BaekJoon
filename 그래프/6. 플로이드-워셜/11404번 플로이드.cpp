#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int MAX = 10000001;

    int iN, iM;
    cin >> iN >> iM;

    vector<vector<int>> vecCost(iN + 1, vector<int>(iN + 1, 0));

    for (int i = 1; i <= iN; ++i)
    {
        for (int j = 1; j <= iN; ++j)
        {
            if (i != j)
                vecCost[i][j] = MAX;
        }
    }

    for (int i = 0; i < iM; ++i)
    {
        int iDepart, iArrive, iCost;
        cin >> iDepart >> iArrive >> iCost;

        if (vecCost[iDepart][iArrive] > iCost)
            vecCost[iDepart][iArrive] = iCost;
    }

    for (int iFirst = 1; iFirst <= iN; ++iFirst)
    {
        for (int iSecond = 1; iSecond <= iN; ++iSecond)
        {
            for (int iThird = 1; iThird <= iN; ++iThird)
            {
                if (vecCost[iSecond][iThird] > vecCost[iSecond][iFirst] + vecCost[iFirst][iThird])
                    vecCost[iSecond][iThird] = vecCost[iSecond][iFirst] + vecCost[iFirst][iThird];
            }
        }
    }

    for (int i = 1; i <= iN; ++i)
    {
        for (int j = 1; j <= iN; ++j)
        {
            if (vecCost[i][j] == MAX)
                cout << "0 ";
            else
                cout << vecCost[i][j] << ' ';
        }
        cout << '\n';
    }
}