/*
* @title    : 12100�� 2048(Easy)(���2)
* @content  : ���Ʈ ���� - ��Ʈ����ũ
* @author   : �յ���
* @date     : 240905
* @time     : 4 ms
* @memory   : 2024 KB
* @state    : �Ϸ�
*/
#include <iostream>
#include <string.h>

using namespace std;

typedef pair<int, int> Pos;

int N;
int Board[20][20];
int Result = 0;
void Move(int num)
{
    int Temp[20][20];
    memset(Temp, 0, sizeof(Temp));
    
    for (int i = 0; i < N; ++i)
    {
        if (num == 0) // ����������
        {
            int Count = N - 1;
            int pre = 0;
            for (int j = (N - 1); j >= 0; --j)
            {
                if (!Board[i][j]) continue;

                if (pre & Board[i][j])
                {
                    Temp[i][Count + 1] += pre;
                    pre = 0;
                }
                else
                {
                    pre = Board[i][j];
                    Temp[i][Count] = pre;
                    --Count;
                }
            }
        }
        else if (num == 1) // ��������
        {
            int Count = 0;
            int pre = 0;
            for (int j = 0; j < N; ++j)
            {
                if (!Board[i][j]) continue;
            
                if (pre & Board[i][j])
                {
                    Temp[i][Count - 1] += pre;
                    pre = 0;
                }
                else
                {
                    pre = Board[i][j];
                    Temp[i][Count] = pre;
                    ++Count;
                }
            }
        }
        else if (num == 2) // �Ʒ�������
        {
            int Count = N - 1;
            int pre = 0;
            for (int j = (N - 1); j >= 0; --j)
            {
                if (!Board[j][i]) continue;

                if (pre & Board[j][i])
                {
                    Temp[Count + 1][i] += pre;
                    pre = 0;
                }
                else
                {
                    pre = Board[j][i];
                    Temp[Count][i] = pre;
                    --Count;
                }
            }
        }
        else // ��������
        {
            int Count = 0;
            int pre = 0;
            for (int j = 0; j < N; ++j)
            {
                if (!Board[j][i]) continue;

                if (pre & Board[j][i])
                {
                    Temp[Count - 1][i] += pre;
                    pre = 0;
                }
                else
                {
                    pre = Board[j][i];
                    Temp[Count][i] = pre;
                    ++Count;
                }
            }
        }

    }

    memcpy(Board, Temp, sizeof(Board));
}

void DFS(int Count)
{
    if (Count >= 5)
    {
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                if (Board[i][j])
                    Result = max(Result, Board[i][j]);

        return;
    }

    for (int i = 0; i < 4; ++i)
    {
        int Temp[20][20];
        memcpy(Temp, Board, sizeof(Board));
        Move(i);
        DFS(Count + 1);
        memcpy(Board, Temp, sizeof(Board));
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> Board[i][j];
    
    DFS(0);

    cout << Result;

    return 0;
}