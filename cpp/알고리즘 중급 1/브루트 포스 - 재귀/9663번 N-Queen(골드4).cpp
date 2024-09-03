/*
* @title    : 9663번 N-Queen(골드4)
* @content  : 브루트 포스 - 재귀
* @author   : 손동찬
* @date     : 240829
* @time     : 1956 ms
* @memory   : 2024 KB
* @state    : 완료
*/
#include <iostream>
#include <vector>

using namespace std;

int N;
int Result = 0;
vector<bool> rows, diag1, diag2;

void DFS(int Count, int _col)
{
    if (Count >= N)
    {
        ++Result;
        return;
    }

    for (int row = 0; row < N; ++row)
    {
        if (rows[row] || diag1[_col + row] || diag2[_col + (N - 1 - row)])
            continue;
    
        rows[row] = true;
        diag1[_col + row] = true;
        diag2[_col + (N - 1 - row)] = true;
        DFS(Count + 1, _col + 1);
        rows[row] = false;
        diag1[_col + row] = false;
        diag2[_col + (N - 1 - row)] = false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    rows.resize(N, false);
    diag1.resize(N * 2 - 1, false);
    diag2.resize(N * 2 - 1, false);

    DFS(0, 0);

    cout << Result;

    return 0;
} 