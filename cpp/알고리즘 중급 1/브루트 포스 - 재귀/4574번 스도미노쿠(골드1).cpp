/*
* @title    : 4574번 스도미노쿠(골드1)
* @content  : 브루트 포스 - 재귀
* @author   : 손동찬
* @date     : 240903
* @time     : 4 ms
* @memory   : 2020 KB
* @state    : 완료
*/
#include <iostream>
#include <cstring>

using namespace std;

int Board[9][9];
bool dominoes[10][10];
int drow[2] = { 0, 1 };
int dcol[2] = { 1, 0 }; 

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
                for (int num1 = 1; num1 <= 9; ++num1) // 보드를 순회하며 1부터 9까지 시도
                {
                    if (isValid(row, col, num1)) // 같은 숫자가 없다는 조건 통과하면
                    {
                        for (int d = 0; d < 2; d++) //오른쪽 or 아래로 도미노를 배치 
                        {
                            int nrow = row + drow[d];
                            int ncol = col + dcol[d];
                            if (nrow < 9 && ncol < 9 && Board[nrow][ncol] == 0) // 도미노가 밖으로 나가지 않으면
                            {
                                for (int num2 = 1; num2 <= 9; num2++) // 도미노의 두번째 숫자를 1부터 9까지 시도
                                {
                                    if (num1 != num2 && isValid(nrow, ncol, num2) && dominoes[num1][num2]) // 같은 숫자가 없다는 조건 통과하면
                                    {
                                        Board[row][col] = num1;
                                        Board[nrow][ncol] = num2;
                                        dominoes[num1][num2] = false;
                                        dominoes[num2][num1] = false;


                                        if (SolveSudoku())
                                            return true;

                                        //백트래킹

                                        Board[row][col] = 0;
                                        Board[nrow][ncol] = 0;
                                        dominoes[num1][num2] = true;
                                        dominoes[num2][num1] = true;
                                    }
                                }
                            }
                        }                                           
                    }
                }
                return false; // 빈칸에 숫자를 놓을 수 없으면 실패
            }
        }
    }
    return true; // 모든 칸을 채우면 성공
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int case_num = 1;
    int N;
    cin >> N;
    while (N)
    {
        memset(Board, 0, sizeof(Board));
        memset(dominoes, true, sizeof(dominoes));
        
        int iA, iB;
        char cA[3], cB[3];

        for (int i = 0; i < N; ++i)
        {          
            cin >> iA >> cA >> iB >> cB;
            int Arow = cA[0] - 'A';
            int Acol = cA[1] - '1';
            int Brow = cB[0] - 'A';
            int Bcol = cB[1] - '1';

            Board[Arow][Acol] = iA;
            Board[Brow][Bcol] = iB;
            dominoes[iA][iB] = false;
            dominoes[iB][iA] = false;
        }

        char temp[3];
        for (int i = 1; i <= 9; ++i)
        {            
            cin >> temp;
            int tempr = temp[0] - 'A';
            int tempc = temp[1] - '1';
            Board[tempr][tempc] = i;
        }

        SolveSudoku();

        cout << "Puzzle " << case_num << "\n";
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
                cout << Board[i][j];
            cout << "\n";
        }

        ++case_num;
        cin >> N;
    }
    
    return 0;
} 