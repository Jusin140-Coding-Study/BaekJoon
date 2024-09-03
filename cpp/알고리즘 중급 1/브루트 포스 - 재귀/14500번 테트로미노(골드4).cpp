/*
* @title    : 14500번 테트로미노(골드4)
* @content  : 브루트 포스 - 재귀
* @author   : 손동찬
* @date     : 240826
* @time     : 64 ms
* @memory   : 3612 KB
* @state    : 완료
*/
#include <iostream>
#include <vector>

using namespace std;

int N, M;
int MaxResult = 0;
vector<vector<int>> Nums;
vector<vector<bool>> Visited;
int RefX[4] = {1, -1, 0, 0};
int RefY[4] = {0, 0, 1, -1};

void DFS(int _Count, int _X, int _Y, int _Current)
{
    if (_Count == 4)
    {
        MaxResult = max(MaxResult, _Current);
        return;
    }

    for (int i = 0; i < 4; ++i)
    {
        int iX = _X + RefX[i];
        int iY = _Y + RefY[i];

        if (iX >= N || iX < 0 || iY >= M || iY < 0) continue;
        if (Visited[iX][iY]) continue;

        Visited[iX][iY] = true;
        DFS(_Count + 1, iX, iY, _Current + Nums[iX][iY]);
        Visited[iX][iY] = false;
    }
}

void ETC(int _X, int _Y)
{
    if (1 <= _X && N > _X + 1 && M > _Y + 1)
        MaxResult = max(MaxResult, Nums[_X][_Y] + Nums[_X - 1][_Y + 1] + Nums[_X][_Y + 1] + Nums[_X + 1][_Y + 1]);
    if (1 <= _X && N > _X + 1 && 1 <= _Y)
        MaxResult = max(MaxResult, Nums[_X][_Y] + Nums[_X - 1][_Y - 1] + Nums[_X][_Y - 1] + Nums[_X + 1][_Y - 1]);
    if (1 <= _Y && M > _Y + 1 && 1 <= _X)
        MaxResult = max(MaxResult, Nums[_X][_Y] + Nums[_X - 1][_Y - 1] + Nums[_X - 1][_Y] + Nums[_X - 1][_Y + 1]);
    if (1 <= _Y && M > _Y + 1 && N > _X + 1)
        MaxResult = max(MaxResult, Nums[_X][_Y] + Nums[_X + 1][_Y - 1] + Nums[_X + 1][_Y] + Nums[_X + 1][_Y + 1]);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    Nums.resize(N, vector<int>(M));
    Visited.resize(N, vector<bool>(M, false));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> Nums[i][j];

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            Visited[i][j] = true;
            DFS(1, i, j, Nums[i][j]);
            Visited[i][j] = false;
            ETC(i, j);
        }
    }

    cout << MaxResult;

    return 0;
}