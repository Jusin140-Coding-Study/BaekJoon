/*
* @title    : 10989번 수 정렬하기 3(브론즈1)-기수정렬
* @content  : 기수정렬
* @author   : 손동찬
* @date     : 240712
* @time     :  ms
* @memory   :  KB
* @state    : 완료
*/
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int iMaxLength = 0;
    vector<string> v(N);
    vector<queue<string>> vecQue(10);

    for (int i = 0; i < N; ++i)
    {
        cin >> v[i];
        iMaxLength = max(iMaxLength, (int)v[i].size());    
    }

    for (int i = 0; i < iMaxLength; ++i)
    {
        for (int j = 0; j < v.size(); ++j)
        {
            int size = v[j].size();

            if (size > i)
                vecQue[(v[j][size - i - 1] - '0')].push(v[j]);
            else
                vecQue[0].push(v[j]);
        }
        v.clear();

        for (int j = 0; j < 10; ++j)
        {
            while (!(vecQue[j].empty()))
            {
                string Front = vecQue[j].front();
                vecQue[j].pop();
                v.push_back(Front);
            }
        }
    }

    for (int i = 0; i < v.size(); ++i)
        cout << v[i] <<"\n";

    return 0;
}