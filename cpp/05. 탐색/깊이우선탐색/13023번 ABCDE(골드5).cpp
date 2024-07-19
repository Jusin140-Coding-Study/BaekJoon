/*
* @title    : 13023¹ø ABCDE(°ñµå5)
* @content  : ±íÀÌ¿ì¼±Å½»ö
* @author   : ¼Õµ¿Âù
* @date     : 240713
* @time     : 52 ms
* @memory   : 2188 KB
* @state    : ¿Ï·á
*/
#include <iostream>
#include <vector>

using namespace std;

void DFS(int _iNode, int _iDepth, vector<vector<int>>& _v, vector<bool>& _vCheck, bool& _isFind)
{
    if (_isFind) return;

    if (_vCheck[_iNode]) return;

    if (_iDepth == 5)
    {
        _isFind = true;
        return;
    }
    _vCheck[_iNode] = true;
    int iDepth = _iDepth + 1;
    for(int i = 0 ; i < _v[_iNode].size(); ++i)
        DFS(_v[_iNode][i], iDepth, _v, _vCheck, _isFind);

    _vCheck[_iNode] = false;
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> v(N);
    vector<bool> vCheck(N,false);
    for (int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    bool isFind = false;
    for (int i = 0; i < N; ++i) 
    { 
        if (isFind) break;
            
        DFS(i, 1, v, vCheck, isFind);
    }
    cout << isFind;

    return 0;
}