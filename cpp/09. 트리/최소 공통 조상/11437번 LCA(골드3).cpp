/*
* @title    : 11437번 LCA(골드3)
* @content  : 최소 공통 조상
* @author   : 손동찬
* @date     : 240730
* @time     : 964 ms
* @memory   : 9148 KB
* @state    : 완료
*/
#include <iostream>
#include <vector>

using namespace std;

void DFS(int _iIndex, int _iDepth, int _iParent, vector<vector<int>>& _vecNums, vector<pair<int, int>>& _vecDepth, vector<int>& vecVisited)
{
	if (vecVisited[_iIndex]) return;

	vecVisited[_iIndex] = true;
	_vecDepth[_iIndex].first = _iDepth;
	_vecDepth[_iIndex].second = _iParent;

	for (int i = 0; i < _vecNums[_iIndex].size(); ++i)
		DFS(_vecNums[_iIndex][i], _iDepth+1, _iIndex, _vecNums, _vecDepth, vecVisited);
}

int LCA(int _A, int _B, vector<pair<int, int>>& _vecDepth)
{
	while (_vecDepth[_A].first != _vecDepth[_B].first)
	{
		if (_vecDepth[_A].first > _vecDepth[_B].first)
			_A = _vecDepth[_A].second;
		else
			_B = _vecDepth[_B].second;
	}
	
	while (_A != _B)
	{
		_A = _vecDepth[_A].second;
		_B = _vecDepth[_B].second;
	}

	return _A;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N;
	vector<vector<int>> vecNums(N + 1);
	vector<pair<int, int>> vecDepth(N + 1);
	vector<int> vecVisited(N + 1, false);
	for (int i = 0; i < N-1; ++i)
	{
		int a, b;
		cin >> a >> b;
		vecNums[a].push_back(b);
		vecNums[b].push_back(a);
	}

	DFS(1, 0, 0, vecNums, vecDepth, vecVisited);

	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		int a, b;
		cin >> a >> b;
		cout << LCA(a, b, vecDepth) << "\n";
	}

	return 0;
}
