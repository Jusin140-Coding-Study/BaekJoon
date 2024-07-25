/*
* @title    : 17472번 다리 만들기 2(골드1)
* @content  : 최소 신장 트리
* @author   : 손동찬
* @date     : 240725
* @time     : 0ms
* @memory   : 2028 KB
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

const bool compare(Data _A, Data _B)
{
	return _A.Weight < _B.Weight;
}

const int find(int _A, vector<int>& _vecNodes)
{
	if (_A == _vecNodes[_A])
		return _A;
	else
		return _vecNodes[_A] = find(_vecNodes[_A], _vecNodes);
}

void MakeIsland(vector<vector<bool>>& _vecbLand, vector<vector<int>>& _vecIslands, int _IsLandNum, vector<vector<bool>>& _vecCheck, int _N, int _M, vector<int>& _vecMoveX, vector<int>& _vecMoveY)
{
	if (_vecCheck[_N][_M]) return;

	_vecCheck[_N][_M] = true;

	//if (!_vecIslands[_N][_M]) return;
	if (!_vecbLand[_N][_M]) return;


	_vecIslands[_N][_M] = _IsLandNum;

	for (int i = 0; i < 4; ++i)
	{
		int iN = _N + _vecMoveY[i];
		int iM = _M + _vecMoveX[i];

		if (iN < 0 || _vecbLand.size() <= iN || iM < 0 || _vecbLand[i].size() <= iM)
			continue;

		MakeIsland(_vecbLand, _vecIslands, _IsLandNum, _vecCheck, iN, iM, _vecMoveX, _vecMoveY);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	vector<vector<bool>> vecbLand(N, vector<bool>(M));
	vector<vector<int>> vecIslands(N, vector<int>(M));
	vector<vector<bool>> vecCheck(N, vector<bool>(M, false));

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
		{
			cin >> vecIslands[i][j]; 
			vecbLand[i][j] = vecIslands[i][j];
		}
	int IslandNum = 0;
	vector<int> vecMoveX = {0, 0, -1, 1};
	vector<int> vecMoveY = {-1, 1, 0, 0};
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (vecCheck[i][j]) continue;
			if (!vecbLand[i][j]) continue;

			++IslandNum;
			MakeIsland(vecbLand, vecIslands, IslandNum, vecCheck, i, j, vecMoveX, vecMoveY);
		}
	}

	vector<Data> vecDatas;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (!vecIslands[i][j]) continue;
	
			int iN = i+1;
			int iM = j+1;
	
			if (iN + 2 < N && vecIslands[i][j] != vecIslands[iN][j])
			{
				if (!vecIslands[iN][j] && !vecIslands[iN+1][j])
				{
					iN += 2;
					while (iN < N)
					{
						if(vecIslands[i][j] == vecIslands[iN][j])
							break;

						if (vecIslands[iN][j] && vecIslands[i][j] != vecIslands[iN][j])
						{
							vecDatas.push_back(Data{ vecIslands[i][j],vecIslands[iN][j],iN - i - 1 });
							break;
						}
						++iN;
					}
				}
			}
	
			if (iM + 2 < M && vecIslands[i][j] != vecIslands[i][iM])
			{
				if (!vecIslands[i][iM] && !vecIslands[i][iM + 1])
				{
					iM += 2;
					while (iM < M)
					{
						if (vecIslands[i][j] == vecIslands[i][iM])
							break;

						if (vecIslands[i][iM] && vecIslands[i][j] != vecIslands[i][iM])
						{
							vecDatas.push_back(Data{ vecIslands[i][j],vecIslands[i][iM],iM - j - 1 });
							break;
						}
						++iM;
					}
				}
	
			}
		}
	}

	vector<int> vecNodes(IslandNum + 1);
	for (int i = 1; i <= IslandNum; ++i)
		vecNodes[i] = i;

	sort(vecDatas.begin(), vecDatas.end(), compare);
	
	int iCount = 0;
	int iSum = 0;
	for (int i = 0; i < vecDatas.size(); ++i)
	{
		int A = find(vecDatas[i].Start, vecNodes);
		int B = find(vecDatas[i].End, vecNodes);
	
		if (A == B) continue;
	
		vecNodes[A] = vecNodes[B];
		++iCount;
		iSum += vecDatas[i].Weight;
	
		if (iCount >= IslandNum - 1) break;
	}
	
	if(iCount >= IslandNum - 1)
		cout << iSum;
	else
		cout << -1;

	return 0;
}
