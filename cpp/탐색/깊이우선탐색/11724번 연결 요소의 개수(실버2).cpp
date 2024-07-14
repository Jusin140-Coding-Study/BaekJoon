/*
* @title    : 11724번 연결 요소의 개수(실버2)
* @content  : 깊이우선탐색
* @author   : 손동찬
* @date     : 240713
* @time     : 76 ms
* @memory   : 6388 KB
* @state    : 완료
*/
#include <iostream>
#include <vector>

using namespace std;

void DFS(vector<vector<int>>& _vec, vector<bool>& _vecCheck, int iStartNode)
{
    if (_vecCheck[iStartNode]) 
        return;

    _vecCheck[iStartNode] = true;

    for (int i = 0; i < _vec[iStartNode].size(); ++i)
        DFS(_vec, _vecCheck, _vec[iStartNode][i]);         
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> v(N + 1);
    for (int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vector<bool> vCheck(N + 1, false);
    vCheck[0] = true;

    int iDFSCount = 0;

    for (int i = 1; i <= N; ++i)
    {
        if (!vCheck[i])
        {
            DFS(v, vCheck, i);
            iDFSCount++;
        }
    }
    cout << iDFSCount << "\n";

    return 0;
}