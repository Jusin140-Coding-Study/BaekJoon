#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int iT;
    cin >> iT;

    int iInput1, iInput2;
    int iNum1, iNum2;
    int iRemainder;

    for (int i = 0; i < iT; ++i)
    {
        cin >> iInput1 >> iInput2;

        iNum1 = iInput1 > iInput2 ? iInput1 : iInput2;
        iNum2 = iInput1 < iInput2 ? iInput1 : iInput2;

        while (true)
        {
            iRemainder = iNum1 % iNum2;

            if (iRemainder == 0)
                break;

            iNum1 = iNum2;
            iNum2 = iRemainder;
        }

        cout << iInput1 * iInput2 / iNum2 << '\n';
    }
    return 0;
}