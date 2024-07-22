#include <iostream>
#include <vector>
using namespace std;

void Union(vector<int>& vecNums, int iNum1, int iNum2);
void Find(vector<int>& vecNums, int iNum1, int iNum2);
int FindRep(vector<int>& vecNums, int iNum);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int iN, iM;

    cin >> iN >> iM;

    vector<int>    vecNums(iN + 1);

    for (int i = 0; i <= iN; ++i)
        vecNums[i] = i;

    int iOp, iNum1, iNum2;

    for (int i = 0; i < iM; ++i)
    {
        cin >> iOp >> iNum1 >> iNum2;

        // find
        if (iOp)
        {
            Find(vecNums, iNum1, iNum2);
        }

        // union
        else
        {
            Union(vecNums, iNum1, iNum2);
        }
    }
}

void Union(vector<int>& vecNums, int iNum1, int iNum2)
{
    iNum1 = FindRep(vecNums, iNum1);
    iNum2 = FindRep(vecNums, iNum2);

    if (iNum1 != iNum2)
        vecNums[iNum2] = iNum1;
}

void Find(vector<int>& vecNums, int iNum1, int iNum2)
{
    FindRep(vecNums, iNum1);
    FindRep(vecNums, iNum2);

    if (vecNums[iNum1] == vecNums[iNum2])
        cout << "YES\n";
    else
        cout << "NO\n";
}

int FindRep(vector<int>& vecNums, int iNum)
{
    if (iNum != vecNums[iNum])
    {
        return vecNums[iNum] = FindRep(vecNums, vecNums[iNum]);
    }

    else
        return vecNums[iNum];
}
