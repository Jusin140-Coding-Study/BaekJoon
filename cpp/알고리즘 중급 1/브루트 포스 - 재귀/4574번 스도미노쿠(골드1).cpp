/*
* @title    : 4574�� �����̳���(���1)
* @content  : ���Ʈ ���� - ���
* @author   : �յ���
* @date     : 240903
* @time     : 4 ms
* @memory   : 2020 KB
* @state    : �Ϸ�
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
                for (int num1 = 1; num1 <= 9; ++num1) // ���带 ��ȸ�ϸ� 1���� 9���� �õ�
                {
                    if (isValid(row, col, num1)) // ���� ���ڰ� ���ٴ� ���� ����ϸ�
                    {
                        for (int d = 0; d < 2; d++) //������ or �Ʒ��� ���̳븦 ��ġ 
                        {
                            int nrow = row + drow[d];
                            int ncol = col + dcol[d];
                            if (nrow < 9 && ncol < 9 && Board[nrow][ncol] == 0) // ���̳밡 ������ ������ ������
                            {
                                for (int num2 = 1; num2 <= 9; num2++) // ���̳��� �ι�° ���ڸ� 1���� 9���� �õ�
                                {
                                    if (num1 != num2 && isValid(nrow, ncol, num2) && dominoes[num1][num2]) // ���� ���ڰ� ���ٴ� ���� ����ϸ�
                                    {
                                        Board[row][col] = num1;
                                        Board[nrow][ncol] = num2;
                                        dominoes[num1][num2] = false;
                                        dominoes[num2][num1] = false;


                                        if (SolveSudoku())
                                            return true;

                                        //��Ʈ��ŷ

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
                return false; // ��ĭ�� ���ڸ� ���� �� ������ ����
            }
        }
    }
    return true; // ��� ĭ�� ä��� ����
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