#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int iN;
    cin >> iN;

    int iSum = 0;

    vector<int> vecInput(iN, 0);

    for (int i = 0; i < iN; ++i)
        cin >> vecInput[i];

    if (vecInput.size() == 1)
    {
        cout << vecInput[0];
        return 0;
    }

    sort(vecInput.begin(), vecInput.end());

    int iNegCheck = 0;

    for (iNegCheck = 0; iNegCheck < iN; iNegCheck += 2)
    {
        if (vecInput[iNegCheck] <= 0 && vecInput[iNegCheck + 1] <= 0)
        {
            iSum += (vecInput[iNegCheck] * vecInput[iNegCheck + 1]);
        }

        else
            break;
    }

    for (int i = iN - 1; i >= iNegCheck; i -= 2)
    {
        if (i - 1 >= iNegCheck && vecInput[i - 1] >= 2)
        {
            iSum += (vecInput[i] * vecInput[i - 1]);
        }
        else if (i - 1 >= iNegCheck)
        {
            if (vecInput[i] <= 0 && vecInput[i - 1] <= 0)
            {
                iSum += (vecInput[i] * vecInput[i - 1]);
            }

            else
            {
                iSum += vecInput[i];
                iSum += vecInput[i - 1];
            }
        }
        else
        {
            iSum += vecInput[i];
        }
    }

    cout << iSum;
}