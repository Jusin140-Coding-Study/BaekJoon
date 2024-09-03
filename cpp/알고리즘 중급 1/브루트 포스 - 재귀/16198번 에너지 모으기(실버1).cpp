/*
* @title    : 16198번 에너지 모으기(실버1)
* @content  : 브루트 포스 - 재귀
* @author   : 손동찬
* @date     : 240828
* @time     : 12 ms
* @memory   : 2024 KB
* @state    : 완료
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