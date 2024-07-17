#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int iM, iN;
    cin >> iM >> iN;

    vector<bool> vecInput(iN + 1, true);

    for (int i = 2; i <= iN; ++i)
    {
        if (!vecInput[i])
            continue;

        for (int j = 2; j <= iN; ++j)
        {
            if (i * j > iN)
                break;

            vecInput[i * j] = false;
        }

        if (i >= iM && vecInput[i])
            cout << i << '\n';
    }
}