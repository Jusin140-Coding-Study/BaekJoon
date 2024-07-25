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

    vector<vector<int>> vecAdj(iN, vector<int>(iN, 0));

    for (int i = 0; i < iN; ++i)
    {
        for (int j = 0; j < iN; ++j)
        {
            cin >> vecAdj[i][j];
        }
    }

    for (int iFirst = 0; iFirst < iN; ++iFirst)
    {
        for (int iSecond = 0; iSecond < iN; ++iSecond)
        {
            for (int iThird = 0; iThird < iN; ++iThird)
            {
                if (vecAdj[iSecond][iFirst] && vecAdj[iFirst][iThird])
                    vecAdj[iSecond][iThird] = 1;
            }
        }
    }

    for (int i = 0; i < iN; ++i)
    {
        for (int j = 0; j < iN; ++j)
        {
            cout << vecAdj[i][j] << ' ';
        }
        cout << '\n';
    }
}