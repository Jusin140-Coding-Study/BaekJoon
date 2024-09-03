/*
* @title    : 2580번 스도쿠(골드4)
* @content  : 브루트 포스 - 재귀
* @author   : 손동찬
* @date     : 240829
* @time     : 248 ms
* @memory   : 2020 KB
* @state    : 완료
*/
#include <iostream>

using namespace std;

int Board[9][9];

bool isValid(int row, int col, int num) 
{
    for (int i = 0; i < 9; ++i) 
    {
        if (Board[row][i] == num || Board[i][col] == num)
            return false;
    }

    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;
    for (int i = 0; i < 3; ++i) 
    {
        for (int j = 0; j < 3; ++j)
        {
            if (Board[startRow + i][startCol + j] == num)
                return false;
        }
    }

    return true;
}

bool SolveSudoku() 
{
    for (int row = 0; row < 9; ++row) 
    {
        for (int col = 0; col < 9; ++col) 
        {
            if (Board[row][col] == 0) 
            {
                for (int num = 1; num <= 9; ++num) 
                {
                    if (isValid(row, col, num)) 
                    {
                        Board[row][col] = num;
                        if (SolveSudoku())
                            return true;
                        Board[row][col] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    for (int i = 0; i < 9; ++i)
        for (int j = 0; j < 9; ++j)
            cin >> Board[i][j];
        
    SolveSudoku();

    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
            cout << Board[i][j] << " ";
        cout << "\n";
    }

    return 0;
} 