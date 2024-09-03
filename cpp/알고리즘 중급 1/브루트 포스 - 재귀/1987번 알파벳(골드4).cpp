/*
* @title    : 1987번 알파벳(골드4)
* @content  : 브루트 포스 - 재귀
* @author   : 손동찬
* @date     : 240830
* @time     : 460 ms
* @memory   : 2028 KB
* @state    : 완료
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int R, C, Result = 0;
vector<vector<int>> Board;
bool Visited[26];
int MoveX[4] = { 1, -1, 0, 0 };
int MoveY[4] = { 0, 0, 1, -1 };

void DFS(int CurX, int CurY, int Count)
{
    bool b = true;
    for (int i = 0; i < 4; ++i)
    {
        int X = CurX + MoveX[i];
        int Y = CurY + MoveY[i];

        if (X < 0 || C <= X || Y < 0 || R <= Y)
            continue;

        if (Visited[Board[Y][X]])
            continue;

        Visited[Board[Y][X]] = true;
        b = false;
        DFS(X, Y, Count + 1);
        Visited[Board[Y][X]] = false;
    }

    if (b)
        Result = max(Result, Count);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> R >> C;
    Board.resize(R, vector<int>(C));
    for (int i = 0; i < R; ++i)
    {
        string a;
        cin >> a;
        for (int j = 0; j < C; ++j)
            Board[i][j] = a[j]-'A';
    }

    Visited[Board[0][0]] = true;
    DFS(0, 0, 1);

    cout << Result;

    return 0;
}