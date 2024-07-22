#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(vector<vector<int>>& vecNodes, vector<bool>& vecVisited, queue<int>& qNodes, vector<int>& vecDist, int iX, int iK);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM, iK, iX;
	cin >> iN >> iM >> iK >> iX;

	vector<vector<int>> vecNodes(iN + 1);
	vector<bool>		vecVisited(iN + 1, false);
	queue<int>			qNodes;
	vector<int>			vecDist(iN + 1, 0);

	int iNode1, iNode2;

	for (int i = 0; i < iM; ++i)
	{
		cin >> iNode1 >> iNode2;
		vecNodes[iNode1].push_back(iNode2);
	}

	qNodes.push(iX);
	vecVisited[iX] = true;
	BFS(vecNodes, vecVisited, qNodes, vecDist, iX, iK);

	bool hasResult = false;

	for (int i = 0; i < iN + 1; ++i)
	{
		if (iK == vecDist[i])
		{
			cout << i << '\n';
			hasResult = true;
		}
	}

	if (!hasResult)
		cout << -1;

	return 0;
}

void BFS(vector<vector<int>>& vecNodes, vector<bool>& vecVisited, queue<int>& qNodes, vector<int>& vecDist, int iX, int iK)
{
	int iCurNode;

	while (!qNodes.empty())
	{
		iCurNode = qNodes.front();
		qNodes.pop();

		for (int i = 0; i < vecNodes[iCurNode].size(); ++i)
		{
			int iNext = vecNodes[iCurNode][i];

			if (vecVisited[iNext])
				continue;

			vecVisited[iNext] = true;

			vecDist[iNext] = vecDist[iCurNode] + 1;

			if (iK == vecDist[iNext])
				continue;

			qNodes.push(iNext);
		}
	}
}