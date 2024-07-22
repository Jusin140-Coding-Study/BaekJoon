#include <iostream>
using namespace std;

long long GCD(long long lNum1, long long lNum2)
{
    return (0 == lNum2) ? lNum1 : GCD(lNum2, lNum1 % lNum2);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long lNum1, lNum2;
    cin >> lNum1 >> lNum2;

    if (lNum1 < lNum2)
    {
        long long iTemp = lNum1;
        lNum1 = lNum2;
        lNum2 = iTemp;
    }

    long long lRemainder = GCD(lNum1, lNum2);

    while (lRemainder--)
        cout << 1;

    return 0;
}