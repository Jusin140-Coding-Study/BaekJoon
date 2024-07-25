/*
* @title    : 1197번 최소 스패닝 트리(골드4)
* @content  : 최소 신장 트리
* @author   : 손동찬
* @date     : 240725
* @time     : 36 ms
* @memory   : 3356 KB
* @state    : 완료
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Data
{
	int Start;
	int End;
	int Weight;
};

bool compare(Data _A, Data _B)
{
	return _A.Weight < _B.Weight;
}

int find(int _A, vector<int>& _vecNodes)
{
	if (_A == _vecNodes[_A])
		return _A;
	else
		return _vecNodes[_A] = find(_vecNodes[_A], _vecNodes);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int V, E;
	cin >> V >> E;

	vector<Data> vecDatas(E);
	for (int i = 0; i < E; ++i)
		cin >> vecDatas[i].Start >> vecDatas[i].End >> vecDatas[i].Weight;

	vector<int> vecNodes(V + 1);
	for (int i = 1; i <= V; ++i)
		vecNodes[i] = i;
	
	sort(vecDatas.begin(), vecDatas.end(), compare);
	
	int iCount = 0;
	int iSum = 0;
	for (int i = 0; i < E; ++i)
	{
		int A = find(vecDatas[i].Start, vecNodes);
		int B = find(vecDatas[i].End, vecNodes);

		if (A == B) continue;
			
		vecNodes[A] = vecNodes[B];
		++iCount;
		iSum += vecDatas[i].Weight;

		if (iCount >= V - 1) break;
	}
	
	cout << iSum;

	return 0;
}
