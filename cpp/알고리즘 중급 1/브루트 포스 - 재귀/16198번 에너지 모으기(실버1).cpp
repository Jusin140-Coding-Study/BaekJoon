/*
* @title    : 16198�� ������ ������(�ǹ�1)
* @content  : ���Ʈ ���� - ���
* @author   : �յ���
* @date     : 240828
* @time     : 12 ms
* @memory   : 2024 KB
* @state    : �Ϸ�
*/
#include <iostream>
#include <map>

using namespace std;

int N;
int Result = 0;
map<int, int> Energys;

void DFS(int Count, int Currnet)
{
    if (Count <= 2)
    {
        Result = max(Result, Currnet);
        return;
    }

    for (int i = 1; i < N-1; ++i)
    {
        if (!Energys[i])
            continue;
        
        int front = i - 1;
        int back = i + 1;
        while (!Energys[front]) --front;
        while (!Energys[back]) ++back;


        int Temp = Energys[i];
        Energys[i] = 0;
        DFS(Count - 1, Currnet + (Energys[front]* Energys[back]));
        Energys[i] = Temp;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int Energy;
        cin >> Energy;
        Energys[i] = Energy;
    }
    DFS(N, 0);

    cout << Result;

    return 0;
} 