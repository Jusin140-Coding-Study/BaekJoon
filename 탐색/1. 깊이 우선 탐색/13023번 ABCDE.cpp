#include <iostream>
#include <vector>
using namespace std;

bool DFS(int iCurNode, vector<vector<int>>& vecAdj, vector<bool>& vecVisit, int iFriendShip);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int iN, iM;
    cin >> iN >> iM;

    vector<vector<int>>    vecAdj(iN);
    vector<bool>           vecVisit(iN, false);

    int iFriend1, iFriend2;

    for (int i = 0; i < iM; ++i)
    {
        cin >> iFriend1 >> iFriend2;

        vecAdj[iFriend1].push_back(iFriend2);
        vecAdj[iFriend2].push_back(iFriend1);
    }


    int iFriendShip;

    for (int i = 0; i < iN; ++i)
    {
        if (vecAdj[i].empty())
            continue;

        iFriendShip = 0;
        fill(vecVisit.begin(), vecVisit.end(), false);

        vecVisit[i] = true;
        if (DFS(i, vecAdj, vecVisit, iFriendShip))
        {
            cout << "1\n";
            return 0;
        }
    }

    cout << "0\n";
}

bool DFS(int iCurNode, vector<vector<int>>& vecAdj, vector<bool>& vecVisit, int iFriendShip)
{
    iFriendShip++;

    if (iFriendShip >= 5)
    {
        return true;
    }

    int iNextNode;

    for (int i = 0; i < vecAdj[iCurNode].size(); ++i)
    {
        iNextNode = vecAdj[iCurNode][i];

        if (!vecVisit[iNextNode])
        {
            vecVisit[iNextNode] = true;
            if (DFS(iNextNode, vecAdj, vecVisit, iFriendShip))
                return true;

            vecVisit[iNextNode] = false;
        }
    }

    return false;
}