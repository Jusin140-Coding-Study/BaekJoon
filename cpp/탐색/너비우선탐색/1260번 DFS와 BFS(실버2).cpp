/*
* @title    : 1260번 DFS와 BFS(실버2)
* @content  : 너비우선탐색
* @author   : 손동찬
* @date     : 240713
* @time     : 0ms
* @memory   : 2304 KB
* @state    : 완료
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void DFS(int iNode, vector<vector<int>>& _vecNodeData, vector<bool>& vecNodeCheck)
{
    if (vecNodeCheck[iNode]) return;

    vecNodeCheck[iNode] = true;
    cout << iNode << " ";

    for (int i = 0; i < _vecNodeData[iNode].size(); ++i)
        DFS(_vecNodeData[iNode][i], _vecNodeData, vecNodeCheck);   

    return;
}

void BFS(vector<vector<int>>& _vecNodeData, vector<bool>& vecNodeCheck, queue<int>& _queNode)
{
    while (!_queNode.empty())
    {
        int iFront = _queNode.front();
        _queNode.pop();
        cout << iFront << " ";
        for (int i = 0; i < _vecNodeData[iFront].size(); ++i)
        {
            if (vecNodeCheck[_vecNodeData[iFront][i]]) continue;

            _queNode.push(_vecNodeData[iFront][i]);
            vecNodeCheck[_vecNodeData[iFront][i]] = true;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, V;
    cin >> N >> M >> V;
    vector<vector<int>> vecNodeData(N + 1);
    vector<bool> vecNodeCheck(N+1, false);
    queue<int> queNode;

    for (int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
        vecNodeData[a].push_back(b);
        vecNodeData[b].push_back(a);
    }

    for (int i = 0; i <= N; ++i)
        sort(vecNodeData[i].begin(), vecNodeData[i].end());
        
    DFS(V, vecNodeData, vecNodeCheck);
    cout << "\n";
    vecNodeCheck.assign(vecNodeCheck.size(), false);
    queNode.push(V);
    vecNodeCheck[V] = true;
    BFS(vecNodeData, vecNodeCheck, queNode);

    return 0;
}