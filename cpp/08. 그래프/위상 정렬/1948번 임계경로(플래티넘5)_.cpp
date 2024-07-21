/*
* @title    : 1948번 임계경로(플래티넘5)
* @content  : 위상 정렬
* @author   : 손동찬
* @date     : 240721
* @time     :  ms
* @memory   :  KB
* @state    : 완료
*/
#include <iostream>
#include <vector>

using namespace std;

struct CityData
{
	int CityNum;
	int Distance;
	int Serial;
};

void DFS(int _Node, int& _EndNode, vector<vector<CityData>>& _vecData, vector<bool>& vecSerials, vector<bool>& vecResult, int& _MaxDistance, int& _CurrentDistance)
{
	if (_Node == _EndNode)
	{
		if (_CurrentDistance > _MaxDistance)
		{
			_MaxDistance = _CurrentDistance;
			vecResult = vecSerials;
			return;
		}
		else if (_CurrentDistance == _MaxDistance)
		{
			for (int i = 0; i < vecSerials.size(); ++i)
				if (vecSerials[i])
					if(!vecResult[i])
						vecResult[i] = true;
			return;
		}
		return;
	}

	for (int i = 0; i < _vecData[_Node].size(); ++i)
	{
		_CurrentDistance += _vecData[_Node][i].Distance;
		vecSerials[_vecData[_Node][i].Serial] = true;
		DFS(_vecData[_Node][i].CityNum, _EndNode, _vecData, vecSerials, vecResult, _MaxDistance, _CurrentDistance);
		_CurrentDistance -= _vecData[_Node][i].Distance;
		vecSerials[_vecData[_Node][i].Serial] = false;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	vector<vector<CityData>> vecData(N + 1);
	for (int i = 0; i < M; ++i)
	{
		int iNum;
		CityData MyData;
		cin >> iNum >> MyData.CityNum >> MyData.Distance;
		MyData.Serial = i;
		vecData[iNum].push_back(MyData);
	}
	int S, E;
	cin >> S >> E;

	vector<bool> vecSerials(M, false);
	vector<bool> vecResult(M, false);
	int MaxDistance = 0;
	int CurrentDistance = 0;
	DFS(S, E, vecData, vecSerials, vecResult, MaxDistance, CurrentDistance);

	int iCount = 0;
	for (int i = 0; i < M; ++i)
		if (vecResult[i])
			++iCount;

	cout << MaxDistance << "\n" << iCount;

	return 0;
}
