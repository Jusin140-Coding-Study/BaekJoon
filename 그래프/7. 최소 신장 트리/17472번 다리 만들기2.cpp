#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

typedef tuple<int, int, int> Edge;

static int arrR[] = { -1, 0, 1, 0 };
static int arrC[] = { 0, 1, 0, -1 };

void	BFS(vector<vector<int>>& vecMap, vector<vector<bool>>& vecVisited, int i, int j, int iIslandNum, int iN, int iM, vector<pair<int, int>>& vecCurIsland);
void	Union(vector<int>& vecUnionFind, int iA, int iB);
int		Find(vector<int>& vecUnionFind, int iA);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM;
	cin >> iN >> iM;

	vector<vector<int>> vecMap(iN, vector<int>(iM, 0));
	priority_queue<Edge, vector<Edge>, greater<Edge>> pqIsland;

	for (int iOuter = 0; iOuter < iN; ++iOuter)
	{
		for (int iInner = 0; iInner < iM; ++iInner)
		{
			cin >> vecMap[iOuter][iInner];
		}
	}

	int iIslandCnt = 1;

	vector<vector<bool>> vecVisited(iN, vector<bool>(iM, false));
	vector<pair<int, int>> vecCurIsland;
	vector<vector<pair<int, int>>> vecIsland;

	for (int i = 0; i < iN; ++i)
	{
		for (int j = 0; j < iM; ++j)
		{
			if (vecMap[i][j] != 0 && !vecVisited[i][j])
			{
				BFS(vecMap, vecVisited, i, j, iIslandCnt, iN, iM, vecCurIsland);
				iIslandCnt++;
				vecIsland.push_back(vecCurIsland);
			}
		}
	}

	vector<int> vecUnionFind(iIslandCnt);
	for (int i = 0; i < iIslandCnt; ++i)
		vecUnionFind[i] = i;

	int iRow, iCol;
	int iDirR, iDirC;
	int iNextR, iNextC;
	int iLength = 0;
	int iIslandNum = 1;

	for (int i = 0; i < vecIsland.size(); ++i)
	{
		vecCurIsland = vecIsland[i];

		for (int j = 0; j < vecCurIsland.size(); ++j)
		{
			iRow = vecCurIsland[j].first;
			iCol = vecCurIsland[j].second;
			iIslandNum = vecMap[iRow][iCol];

			for (int iDir = 0; iDir < 4; ++iDir)
			{
				iDirR = arrR[iDir];
				iDirC = arrC[iDir];
				iLength = 0;

				while (iRow + iDirR >= 0 && iRow + iDirR < iN && iCol + iDirC >= 0 && iCol + iDirC < iM)
				{
					iNextR = iRow + iDirR;
					iNextC = iCol + iDirC;

					// 같은 섬인지 확인
					if (vecMap[iNextR][iNextC] == iIslandNum)
						break;

					// 다른 섬인지 확인
					else if (0 != vecMap[iNextR][iNextC])
					{
						// 다리 길이가 2 이상인지 확인
						if (1 < iLength)
							pqIsland.push(Edge(iLength, iIslandNum, vecMap[iNextR][iNextC]));

						break;
					}

					// 바다인지 확인
					else
						iLength++;

					if (iDirR < 0)
						iDirR--;
					else if (iDirR > 0)
						iDirR++;
					else if (iDirC < 0)
						iDirC--;
					else if (iDirC > 0)
						iDirC++;
				}
			}
		}
	}

	Edge eCurEdge;
	int iIsland1, iIsland2, iWeight;

	int iResult = 0;
	int iEdgeCnt = 0;

	while (!pqIsland.empty())
	{
		eCurEdge = pqIsland.top();
		pqIsland.pop();
		iIsland1 = get<1>(eCurEdge);
		iIsland2 = get<2>(eCurEdge);
		iWeight = get<0>(eCurEdge);

		if (Find(vecUnionFind, iIsland1) != Find(vecUnionFind, iIsland2))
		{
			Union(vecUnionFind, iIsland1, iIsland2);
			iResult += iWeight;
			iEdgeCnt++;
		}
	}

	if (iEdgeCnt == iIslandCnt - 2)
		cout << iResult;

	else
		cout << -1;

	return 0;
}

void BFS(vector<vector<int>>& vecMap, vector<vector<bool>>& vecVisited, int i, int j, int iIslandNum, int iN, int iM, vector<pair<int, int>>& vecCurIsland)
{
	queue<pair<int, int>> qIsland;
	vecCurIsland.clear();

	qIsland.push(make_pair(i, j));
	vecVisited[i][j] = true;
	vecMap[i][j] = iIslandNum;
	vecCurIsland.push_back(make_pair(i, j));
	
	int iRow, iCol;
	int iDirR, iDirC;
	int iNextR, iNextC;

	while (!qIsland.empty())
	{
		iRow = qIsland.front().first;
		iCol = qIsland.front().second;

		qIsland.pop();

		for (int iDir = 0; iDir < 4; ++iDir)
		{
			iDirR = arrR[iDir];
			iDirC = arrC[iDir];

			// 다음 방문할 요소가 배열의 범위를 벗어나지 않는지
			while (iRow + iDirR >= 0 && iRow + iDirR < iN && iCol + iDirC >= 0 && iCol + iDirC < iM)
			{
				iNextR = iRow + iDirR;
				iNextC = iCol + iDirC;

				// 방문한 적이 없고 바다가 아니면 같은 섬
				if (!vecVisited[iNextR][iNextC] && vecMap[iNextR][iNextC] != 0)
				{
					vecMap[iNextR][iNextC] = iIslandNum;
					vecVisited[iNextR][iNextC] = true;
					qIsland.push(make_pair(iNextR, iNextC));
					vecCurIsland.push_back(make_pair(iNextR, iNextC));
				}
				else
					break;

				if (iDirR < 0)
					iDirR--;
				else if (iDirR > 0)
					iDirR++;
				else if (iDirC < 0)
					iDirC--;
				else if (iDirC > 0)
					iDirC++;
			}
		}
	}
}

void	Union(vector<int>& vecUnionFind, int iA, int iB)
{
	if (vecUnionFind[iA] != iA)
	{
		iA = Find(vecUnionFind, iA);
	}

	if (vecUnionFind[iB] != iB)
	{
		iB = Find(vecUnionFind, iB);
	}

	vecUnionFind[iB] = iA;
}

int Find(vector<int>& vecUnionFind, int iA)
{
	if (iA == vecUnionFind[iA])
		return iA;

	return vecUnionFind[iA] = Find(vecUnionFind, vecUnionFind[iA]);
}