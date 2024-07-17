#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(vector<vector<int>>& vecAdj, vector<vector<bool>>& vecVisit, queue<pair<int, int>>& qBFS, int iN, int iM);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int iN, iM;
    cin >> iN >> iM;

    vector<vector<int>>    vecAdj(iN, vector<int>(iM, 0));
    vector<vector<bool>>   vecVisit(iN, vector<bool>(iM, false));
    queue<pair<int, int>>  qBFS;

    string sInput;

    for (int i = 0; i < iN; ++i)
    {
        cin >> sInput;

        for (int j = 0; j < iM; ++j)
        {
            vecAdj[i][j] = sInput[j] - '0';
        }
    }

    BFS(vecAdj, vecVisit, qBFS, iN, iM);

    cout << vecAdj[iN - 1][iM - 1];
}

void BFS(vector<vector<int>>& vecAdj, vector<vector<bool>>& vecVisit, queue<pair<int, int>>& qBFS, int iN, int iM)
{
    int arrX[4] = { 1, 0, -1, 0 };
    int arrY[4] = { 0, 1, 0, -1 };

    int iCurX = 0, iCurY = 0;
    int iNextX, iNextY;

    qBFS.push(make_pair(iCurX, iCurY));

    while (!qBFS.empty())
    {
        iCurX = qBFS.front().first;
        iCurY = qBFS.front().second;
        qBFS.pop();

        vecVisit[iCurX][iCurY] = true;

        for (int i = 0; i < 4; ++i)
        {
            iNextX = iCurX + arrX[i];
            iNextY = iCurY + arrY[i];

            if (iNextX >= 0 && iNextY >= 0 && iNextX < iN && iNextY < iM)
            {
                if (!vecVisit[iNextX][iNextY] && vecAdj[iNextX][iNextY] == 1)
                {
                    vecVisit[iNextX][iNextY] = true;
                    qBFS.push(make_pair(iNextX, iNextY));
                    vecAdj[iNextX][iNextY] = vecAdj[iCurX][iCurY] + 1;
                }
            }
        }
    }
}