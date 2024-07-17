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

    cin >> iN;
    vector<int> vecN(iN, 0);

    for (int i = 0; i < iN; ++i)
        cin >> vecN[i];

    sort(vecN.begin(), vecN.end());

    cin >> iM;
    vector<int> vecM(iM, 0);

    bool    isFind = false;
    int     iStart = 0;
    int     iEnd = vecN.size() - 1;
    int     iCenter = (iEnd - iStart) / 2;

    for (int i = 0; i < iM; ++i)
    {
        cin >> vecM[i];

        isFind = false;
        iStart = 0;
        iEnd = vecN.size() - 1;
        iCenter = (iEnd - iStart) / 2;

        while (iStart <= iEnd)
        {
            if (vecM[i] < vecN[iCenter])
            {
                iEnd = iCenter - 1;
                iCenter = (iStart + iEnd) / 2;
            }

            else if (vecM[i] > vecN[iCenter])
            {
                iStart = iCenter + 1;
                iCenter = (iStart + iEnd) / 2;
            }

            else
            {
                isFind = true;
                break;
            }
        }

        cout << (isFind ? "1\n" : "0\n");
    }
}