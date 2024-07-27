/*
* @title    : 11725번 트리의 부모 찾기(실버2)
* @content  : 트리 알아보기
* @author   : 손동찬
* @date     : 240727
* @time     : 48 ms
* @memory   : 15620 KB
* @state    : 완료
*/
#include <iostream>
#include <vector>

using namespace std;

void DFS(int _iIndex, vector<vector<int>>& _vecDatas, vector<int>& _vecParent, vector<bool>& _vecVisited)
{
	if (_vecVisited[_iIndex]) return;

	_vecVisited[_iIndex] = true;

	for (int i = 0; i < _vecDatas[_iIndex].size(); ++i)
	{
		if(!_vecParent[_vecDatas[_iIndex][i]])
			_vecParent[_vecDatas[_iIndex][i]] = _iIndex;
		DFS(_vecDatas[_iIndex][i], _vecDatas, _vecParent, _vecVisited);
	}
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<vector<int>> vecDatas(N+1);

	for (int i = 1; i < N; ++i)
	{
		int A, B;
		cin >> A >> B;
		vecDatas[A].push_back(B);
		vecDatas[B].push_back(A);
	}

	vector<int> vecParent(N+1,0);
	vector<bool> vecVisited(N + 1, false);

	DFS(1, vecDatas, vecParent, vecVisited);

	for (int i = 2; i <= N; ++i)
		cout << vecParent[i] << "\n";

	return 0;
}
