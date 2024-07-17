#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int iN;
    cin >> iN;

    vector<int> vecInput(iN, 0);

    for (int i = 0; i < iN; ++i)
    {
        cin >> vecInput[i];
    }

    int iTemp;

    for (int i = 0; i < iN; ++i)
    {
        for (int j = 0; j < iN - i - 1; ++j)
        {
            if (vecInput[j] > vecInput[j + 1])
            {
                iTemp = vecInput[j];
                vecInput[j] = vecInput[j + 1];
                vecInput[j + 1] = iTemp;
            }
        }
    }

    for (int i = 0; i < iN; ++i)
    {
        cout << vecInput[i] << '\n';
    }
}