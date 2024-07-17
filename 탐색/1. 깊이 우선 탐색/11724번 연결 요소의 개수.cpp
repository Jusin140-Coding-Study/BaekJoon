#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void DFS(vector<vector<int>>& vecAdj, vector<bool>& vecVisit, stack<int>& stkVisit, int iCurNode)
{
    // 시작 노드 스택이 빌 때까지 반복
    while (!stkVisit.empty())
    {
        // 꺼낸 노드의 인접 노드를 확인하여 스택에 삽입
        for (int i = 0; i < vecAdj[iCurNode].size(); ++i)
        {
            if (!vecVisit[vecAdj[iCurNode][i]])
            {
                stkVisit.push(vecAdj[iCurNode][i]);
                vecVisit[vecAdj[iCurNode][i]] = true;
            }
        }

        iCurNode = stkVisit.top();
        stkVisit.pop();
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int iResult = 0;

    int iN, iM;
    cin >> iN >> iM;

    vector<vector<int>> vecAdj(iN + 1);
    vector<bool> vecVisit(iN + 1, false);

    stack<int> stkVisit;

    int iNode1, iNode2;

    for (int i = 0; i < iM; ++i)
    {
        cin >> iNode1 >> iNode2;

        vecAdj[iNode1].push_back(iNode2);
        vecAdj[iNode2].push_back(iNode1);
    }

    for (int i = 1; i <= iN; ++i)
    {
        if (!vecVisit[i])
        {
            iResult++;
            stkVisit.push(i);
            vecVisit[i] = true;
            DFS(vecAdj, vecVisit, stkVisit, i);
        }
    }

    cout << iResult << '\n';
}