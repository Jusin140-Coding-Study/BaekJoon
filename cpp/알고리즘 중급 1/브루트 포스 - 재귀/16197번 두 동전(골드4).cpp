/*
* @title    : 16197번 두 동전(골드4)
* @content  : 브루트 포스 - 재귀
* @author   : 손동찬
* @date     : 240826
* @time     : 12 ms
* @memory   : 2024 KB
* @state    : 완료
*/
#include <iostream>

using namespace std;

#define MAXCOUNT 11
typedef pair<int, int> Pos;

int N, M;

Pos CoinA = { 0, 0 }; 
Pos CoinB = { 0, 0 };

int Board[21][21]; 

int DirX[4] = { 1, -1, 0, 0 };
int DirY[4] = { 0, 0, 1, -1 };

int minCount = MAXCOUNT;

void DFS(int _Count, Pos _CoinA, Pos _CoinB)
{
    if (_Count >= 10)
        return;

    for (int i = 0; i < 4; ++i)
    {
        Pos TempA = { _CoinA.first + DirX[i], _CoinA.second + DirY[i] };
        Pos TempB = { _CoinB.first + DirX[i], _CoinB.second + DirY[i] };

        if (Board[TempA.first][TempA.second] && Board[TempB.first][TempB.second])
            continue;
        if (Board[TempA.first][TempA.second]) 
            TempA = _CoinA;
        if (Board[TempB.first][TempB.second]) 
            TempB = _CoinB;

        if ((TempA.first > N || TempA.first <= 0 || TempA.second > M || TempA.second <= 0) &&
            (0 < TempB.first && TempB.first <= N && 0 < TempB.second && TempB.second <= M))
        {
            minCount = min(minCount, _Count+1);
            return;
        }
        else if ((TempB.first > N || TempB.first <= 0 || TempB.second > M || TempB.second <= 0) &&
            (0 < TempA.first && TempA.first <= N && 0 < TempA.second && TempA.second <= M))
        {
            minCount = min(minCount, _Count+1);
            return;
        }
        else if ((_CoinA.first > N || _CoinA.first <= 0 || _CoinA.second > M || _CoinA.second <= 0) &&
            (_CoinB.first > N || _CoinB.first <= 0 || _CoinB.second > M || _CoinB.second <= 0))
            return;

        DFS(_Count+1, TempA, TempB);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
        {
            char temp;
            cin >> temp;
            if (temp == '#') Board[i][j] = 1;
            else if (temp == 'o')
            {
                if (!CoinA.first)
                    CoinA = make_pair(i, j);
                else
                    CoinB = make_pair(i, j);
            }
        }
   
    DFS(0, CoinA, CoinB);

    if(minCount == MAXCOUNT)
        cout << -1;
    else
        cout << minCount;

    return 0;
} 