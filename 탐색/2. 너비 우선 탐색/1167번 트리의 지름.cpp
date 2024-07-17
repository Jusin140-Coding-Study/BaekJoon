#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int BFS(vector<vector<pair<int, int>>>& vecAdj, int& iStart, vector<bool>& vecVisited, queue<int>& qBFS, vector<int>& vecDist);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int iV;
    cin >> iV;

    vector<vector<pair<int, int>>>    vecAdj(iV);
    vector<bool>                      vecVisited(iV, false);
    queue<int>                        qBFS;
    vector<int>                       vecDist(iV, 0);

    int iNode1 = 0, iNode2 = 0, iDistance = 0;

    for (int i = 1; i <= iV; ++i)
    {
        cin >> iNode1;

        while (true)
        {
            cin >> iNode2;
            if (iNode2 == -1)
                break;

            cin >> iDistance;

            vecAdj[iNode1 - 1].push_back(make_pair(iNode2 - 1, iDistance));
        }
    }

    int iMaxDist = 0;
    int iDist = 0;

    for (int i = 0; i < iV; ++i)
    {
        vecVisited.assign(iV, false);
        vecDist.assign(iV, 0);

        iDist = BFS(vecAdj, i, vecVisited, qBFS, vecDist);
        if (iMaxDist < iDist)
            iMaxDist = iDist;
    }

    cout << iMaxDist;
}

int BFS(vector<vector<pair<int, int>>>& vecAdj, int& iStart, vector<bool>& vecVisited, queue<int>& qBFS, vector<int>& vecDist)
{
    int iMaxDist = 0;

    int iCurNode = iStart;
    int iNextNode;

    vecVisited[iCurNode] = true;
    qBFS.push(iCurNode);

    while (!qBFS.empty())
    {
        iCurNode = qBFS.front();
        qBFS.pop();

        for (int i = 0; i < vecAdj[iCurNode].size(); ++i)
        {
            iNextNode = vecAdj[iCurNode][i].first;

            if (!vecVisited[iNextNode])
            {
                vecVisited[iNextNode] = true;
                qBFS.push(iNextNode);
                vecDist[iNextNode] = vecDist[iCurNode] + vecAdj[iCurNode][i].second;

                if (iMaxDist < vecDist[iNextNode])
                    iMaxDist = vecDist[iNextNode];
            }
        }
    }

    return iMaxDist;
}