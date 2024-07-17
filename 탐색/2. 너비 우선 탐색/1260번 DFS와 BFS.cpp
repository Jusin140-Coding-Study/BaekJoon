#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

void DFS(vector<vector<int>>& vecAdj, vector<bool>& vecVisit, int iCurNode);
void BFS(vector<vector<int>>& vecAdj, vector<bool>& vecVisit, int iCurNode, queue<int>& qBFS);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int iN, iM, iV;
    cin >> iN >> iM >> iV;

    vector<vector<int>> vecAdj(iN + 1);
    vector<bool>        vecVisit(iN + 1);
    queue<int>          qBFS;

    int iNode1, iNode2;

    for (int i = 0; i < iM; ++i)
    {
        cin >> iNode1 >> iNode2;

        vecAdj[iNode1].push_back(iNode2);
        vecAdj[iNode2].push_back(iNode1);
    }

    for (int i = 0; i <= iN; ++i)
    {
        sort(vecAdj[i].begin(), vecAdj[i].end());
    }

    DFS(vecAdj, vecVisit, iV);
    cout << '\n';

    fill(vecVisit.begin(), vecVisit.end(), false);

    vecVisit[iV] = true;
    qBFS.push(iV);
    BFS(vecAdj, vecVisit, iV, qBFS);
}

void DFS(vector<vector<int>>& vecAdj, vector<bool>& vecVisit, int iCurNode)
{
    cout << iCurNode << ' ';

    vecVisit[iCurNode] = true;

    int iNextNode;

    for (int i = 0; i < vecAdj[iCurNode].size(); ++i)
    {
        iNextNode = vecAdj[iCurNode][i];

        if (!vecVisit[iNextNode])
        {
            DFS(vecAdj, vecVisit, iNextNode);
        }
    }
}

void BFS(vector<vector<int>>& vecAdj, vector<bool>& vecVisit, int iCurNode, queue<int>& qBFS)
{
    int iNextNode;

    while (!qBFS.empty())
    {
        iCurNode = qBFS.front();
        qBFS.pop();

        cout << iCurNode << ' ';

        for (int i = 0; i < vecAdj[iCurNode].size(); ++i)
        {
            iNextNode = vecAdj[iCurNode][i];

            if (!vecVisit[iNextNode])
            {
                vecVisit[iNextNode] = true;
                qBFS.push(iNextNode);
                
            }
        }
    }
}