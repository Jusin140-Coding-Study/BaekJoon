#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void DFS(int iCurNode, int iMax);
bool isPrime(int iNum);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int iN;
    cin >> iN;

    int iMax = pow(10, iN);

    DFS(2, iMax);
    DFS(3, iMax);
    DFS(5, iMax);
    DFS(7, iMax);
}

void DFS(int iCurNode, int iMax)
{
    if (iCurNode >= iMax / 10)
    {
        cout << iCurNode << '\n';
        return;
    }

    for (int i = 0; i < 10; ++i)
    {
        if (i % 2 == 0)
            continue;

        if (isPrime(iCurNode * 10 + i))
            DFS(iCurNode * 10 + i, iMax);
    }
}

bool isPrime(int iNum)
{
    for (int i = 2; i <= iNum / 2; ++i)
    {
        if (iNum % i == 0)
            return false;
    }

    return true;
}