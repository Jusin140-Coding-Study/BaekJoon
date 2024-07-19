/*
* @title    : 2178번 미로탐색(실버1)
* @content  : 너비우선탐색
* @author   : 손동찬
* @date     : 240713
* @time     : 0ms
* @memory   : 2160 KB
* @state    : 완료
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    vector<vector<bool>> vecMazeData(N,vector<bool>(M,false));
    vector<vector<bool>> vecMazeCheck(N, vector<bool>(M, true));

    for (int i = 0; i < N; ++i)
    {
        string strData;
        cin >> strData;
        for (int j = 0; j < M; ++j)
            if (strData[j] == '1') 
                vecMazeData[i][j] = true;
    }

    queue<pair<int, int>> queNode;
    queNode.push({0,0});
    queue<int> queDepth;
    queDepth.push(1);
    vecMazeCheck[0][0] = false;
    int iDepth = 0;
    int DirX[4] = {-1, 1, 0, 0};
    int DirY[4] = {0, 0, -1, 1};

    while (!queNode.empty())
    {
        pair<int,int> pFront = queNode.front();
        queNode.pop();
        iDepth = queDepth.front() +1;
        queDepth.pop();

        if (pFront == pair(N-1, M-1)) 
            break;

        for (int i = 0; i < 4; ++i)
        {
            int X = pFront.first + DirX[i];
            int Y = pFront.second + DirY[i];
            if (0 <= X && X < N && 0 <= Y && Y < M && vecMazeData[X][Y] && vecMazeCheck[X][Y])
            {
                queNode.push({X,Y });
                vecMazeCheck[X][Y] = false;
                queDepth.push(iDepth);
            }
        }
    }

    cout << iDepth-1 << "\n";

    return 0;
}