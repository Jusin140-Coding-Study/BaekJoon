#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long iA, iB;
    cin >> iA >> iB;

    vector<bool> vecPrime(pow(iB, 0.5) + 1, true);

    long iCnt = 0;

    for (long i = 2; i < vecPrime.size(); ++i)
    {
        if (!vecPrime[i])
            continue;

        for (long j = 2; j < vecPrime.size(); ++j)
        {
            if (i * j >= vecPrime.size())
                break;

            vecPrime[i * j] = false;
        }

        for (long j = 2; j < vecPrime.size(); ++j)
        {
            if (pow(i, j) < iA)
                continue;

            else if (pow(i, j) <= iB)
                iCnt++;

            else
                break;
        }
    }

    cout << iCnt;
}