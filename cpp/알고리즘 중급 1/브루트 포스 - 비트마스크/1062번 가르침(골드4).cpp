/*
* @title    : 1062번 가르침(골드4)
* @content  : 브루트 포스 - 비트마스크
* @author   : 손동찬
* @date     : 240902
* @time     : 512 ms
* @memory   : 2024 KB
* @state    : 완료
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N, K;
bool IsKnow[26];
vector<string> vecWords;
int Result = 0;

bool Know(int _Index)
{ 
    if (IsKnow[_Index])
        return false;

    IsKnow[_Index] = true;
    --K;
    return true;
}
void UnKnow(int _Index)
{ 
    if (!IsKnow[_Index])
        return;

    IsKnow[_Index] = false;
    ++K;
}

bool CanRead(string _strWord)
{
    for (int i = 4; i < _strWord.size()-4; ++i)
    {
        int a = _strWord[i] - 'a';
        if (!IsKnow[a])
            return false;
    }

    return true;
}

void Check()
{
    int Count = 0;
    for (int i = 0; i < N; ++i)
        if (CanRead(vecWords[i]))
            ++Count;
    
    Result = max(Result, Count);
}

void DFS(int Start)
{
    if (K == 0 || Start >= 26)
    {
        Check();
        return;
    }

    for (int i = Start; i < 26; ++i)
    {
        if (Know(i))
        {
            DFS(i+1);
            UnKnow(i);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    vecWords.resize(N);

    for (int i = 0; i < N; ++i)
        cin >> vecWords[i];

    string Temp = "antatica";
    for (int i = 0; i < Temp.size(); ++i)
    {
        int a = Temp[i] - 'a';
        Know(a);
    }
    if (K < 0)
    {
        cout << 0;
        return 0;
    }

    DFS(0);

    cout << Result;

    return 0;
} 