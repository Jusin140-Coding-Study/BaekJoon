#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int iN;
    cin >> iN;

    priority_queue<int, vector<int>, greater<int>> pqInput;

    int iInput = 0;

    for (int i = 0; i < iN; ++i)
    {
        cin >> iInput;
        pqInput.push(iInput);
    }

    int iNum1, iNum2;
    int iSum = 0;

    while (pqInput.size() > 1)
    {
        iNum1 = pqInput.top(); pqInput.pop();
        iNum2 = pqInput.top(); pqInput.pop();

        pqInput.push(iNum1 + iNum2);
        iSum += (iNum1 + iNum2);
    }

    cout << iSum;
}