/*
* @title    : 1062번 가르침(골드4)2
* @content  : 브루트 포스 - 비트마스크
* @author   : 손동찬
* @date     : 240904
* @time     : 16 ms
* @memory   : 2024 KB
* @state    : 완료
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N, K;
vector<int> vecWords;
int Result = 0;
int Learned = (1 << ('a' - 'a')) | (1 << ('n' - 'a')) | (1 << ('t' - 'a')) | (1 << ('i' - 'a')) | (1 << ('c' - 'a'));

void DFS(int _Index, int _Count, int _Learned)
{
    if (K <= _Count)
    {
        int iReadable = 0;
        for (int i = 0; i < vecWords.size(); ++i)
            if ((vecWords[i] & _Learned) == vecWords[i])
                ++iReadable;
        
        Result = max(Result, iReadable);
        return;
    }

    for (int i = _Index; i < 26; ++i)
        if (!(Learned & (1 << i)))
            DFS(i + 1, _Count + 1, _Learned | (1 << i));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    if (K < 5)
    {
        cout << 0;
        return 0;
    }

    vecWords.resize(N);
    for (int i = 0; i < N; ++i)
    {
        string strWord;
        cin >> strWord;

        int iWord = 0;
        for (int j = 0; j < strWord.size(); ++j)
            iWord |= (1 << (strWord[j] - 'a'));
        
        vecWords[i] = iWord;
    }

    DFS(0, 5, Learned);

    cout << Result;

    return 0;
}