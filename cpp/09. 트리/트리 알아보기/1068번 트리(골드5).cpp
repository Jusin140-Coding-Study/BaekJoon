/*
* @title    : 1068번 트리(골드5)
* @content  : 트리 알아보기
* @author   : 손동찬
* @date     : 240727
* @time     : 0ms
* @memory   : 2020 KB
* @state    : 완료
*/
#include <iostream>
#include <vector>

using namespace std;

void DFS(int _iIndex, vector<vector<int>>& _vecDatas, int& _iCount, int& _iEraseIndex)
{
	if (_iIndex == _iEraseIndex) return;

	if (_vecDatas[_iIndex].size() == 1 && _vecDatas[_iIndex][0] == _iEraseIndex)
	{
		++_iCount;
		return;
	}

	if (_vecDatas[_iIndex].size() == 0) ++_iCount;

	for (int i = 0; i < _vecDatas[_iIndex].size(); ++i)
		DFS(_vecDatas[_iIndex][i], _vecDatas, _iCount, _iEraseIndex);
	
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N;
	vector<int> vecParents(N);
	for (int i = 0; i < N; ++i)
		cin >> vecParents[i];
	cin >> M;

	int iStartIndex = 0;
	vector<vector<int>> vecDatas(N);
	for (int i = 0; i < N; ++i)
	{
		if (vecParents[i] == -1)
		{
			iStartIndex = i;
			continue;
		}
		vecDatas[vecParents[i]].push_back(i);
	}

	int iCout = 0;

	DFS(iStartIndex, vecDatas, iCout, M);

	cout << iCout;

	return 0;
}
