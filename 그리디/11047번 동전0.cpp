#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int iN, iK;
    cin >> iN >> iK;

    int iCnt = 0, iSum = 0;

    vector<int> vecInput(iN, 0);

    for (int i = 0; i < iN; ++i)
    {
        cin >> vecInput[i];
    }

    int iIdx = iN - 1;

    while (iK > 0)
    {
        if (vecInput[iIdx] <= iK)
        {
            iCnt += (iK / vecInput[iIdx]);
            iK = iK % vecInput[iIdx];
        }
        iIdx--;
    }

    cout << iCnt;
}