#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int iCnt = 0;

    cin >> iCnt;

    vector<int> vecNums(iCnt, 0);
    vector<int> vecNumsCpy(iCnt, 0);
    stack<int> stkNums;

    vector<char> vecResult;

    for (int i = 0; i < iCnt; ++i)
    {
        int iNum;
        cin >> iNum;

        vecNums[i] = iNum;
        vecNumsCpy[i] = iNum;
    }

    sort(vecNums.begin(), vecNums.end());

    int iIdx = 0;

    for (int i = 0; i < iCnt;)
    {
        if (stkNums.size() && stkNums.top() == vecNumsCpy[i])
        {
            stkNums.pop();
            i++;
            vecResult.push_back('-');
        }

        else
        {
            if (iIdx >= iCnt)
            {
                iIdx = 0;
                iCnt = -1;
                break;
            }

            stkNums.push(vecNums[iIdx]);
            iIdx++;
            vecResult.push_back('+');
        }
    }

    if (iIdx != iCnt)
    {
        cout << "NO\n";
    }
    else
    {
        for (int i = 0; i < vecResult.size(); ++i)
            cout << vecResult[i] << "\n";
    }
}