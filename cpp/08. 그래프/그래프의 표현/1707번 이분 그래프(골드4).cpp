/*
* @title    : 1707번 이분 그래프(골드4)
* @content  : 그래프의 표현
* @author   : 손동찬
* @date     : 240719
* @time     : 372 ms
* @memory   : 7084 KB
* @state    : 완료
*/
#include <iostream>
#include <vector>

using namespace std;

void DFS(int _CurrentIndex, vector<vector<int>>& _vecGraph, vector<int>& _vecCheck, vector<int>& _vecGroup, bool& _isBG)
{
	if (!_isBG) return;
	if (_vecCheck[_CurrentIndex]) return;

	_vecCheck[_CurrentIndex] = true;

	for (int i = 0; i < _vecGraph[_CurrentIndex].size(); ++i)
	{
		if (_vecGroup[_vecGraph[_CurrentIndex][i]] == -1)
		{
			if (_vecGroup[_CurrentIndex] == 0) _vecGroup[_vecGraph[_CurrentIndex][i]] = 1;
			else _vecGroup[_vecGraph[_CurrentIndex][i]] = 0;

			DFS(_vecGraph[_CurrentIndex][i], _vecGraph, _vecCheck, _vecGroup, _isBG);
		}
		else
			if (_vecGroup[_CurrentIndex] == _vecGroup[_vecGraph[_CurrentIndex][i]]) _isBG = false;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int K;
	cin >> K;
	for (int i = 0; i < K; ++i)
	{
		int V, E;
		cin >> V >> E;
		vector<vector<int>> vecGraph(V+1);
	
		for (int j = 0; j < E; ++j)
		{
			int a, b;
			cin >> a >> b;
			vecGraph[a].push_back(b);
			vecGraph[b].push_back(a);
		}
		bool isBG = true;
		vector<int> vecCheck(V + 1, false);
		for (int j = 1; j <= V; ++j)
		{
			vector<int> vecGroup(V + 1, -1);
			vecGroup[1] = 0;
			if (!isBG) break;		
			DFS(j, vecGraph, vecCheck, vecGroup, isBG);
		}

		if (isBG) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
