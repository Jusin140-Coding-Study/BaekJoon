#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

void BFS(vector<vector<int>>& vecNodes, vector<bool>& vecVisited, queue<int>& qNodes, vector<int>& vecConnect, int iStart);

int main()
{
	int iN, iM;
	cin >> iN >> iM;

	vector<vector<int>> vecNodes(iN + 1);
	vector<bool>		vecVisited(iN + 1);
	vector<int>			vecConnect(iN + 1, 0);
	queue<int>			qNodes;


	int iNode1, iNode2;

	for (int i = 0; i < iM; ++i)
	{
		cin >> iNode1 >> iNode2;

		vecNodes[iNode1].push_back(iNode2);
	}

	for (int i = 1; i <= iN; ++i)
	{
		fill(vecVisited.begin(), vecVisited.end(), false);
		BFS(vecNodes, vecVisited, qNodes, vecConnect, i);
	}

	int iMax = *max_element(vecConnect.begin(), vecConnect.end());

	for (int i = 1; i <= iN; ++i)
	{
		if (iMax == vecConnect[i])
			cout << i << ' ';
	}

	return 0;
}

void BFS(vector<vector<int>>& vecNodes, vector<bool>& vecVisited, queue<int>& qNodes, vector<int>& vecConnect, int iCurNode)
{
	int iNextNode;

	qNodes.push(iCurNode);
	vecVisited[iCurNode] = true;

	while (!qNodes.empty())
	{
		iCurNode = qNodes.front();
		qNodes.pop();

		for (int i = 0; i < vecNodes[iCurNode].size(); ++i)
		{
			iNextNode = vecNodes[iCurNode][i];

			if (vecVisited[iNextNode])
				continue;

			if (iCurNode != iNextNode)
				vecConnect[iNextNode]++;

			qNodes.push(iNextNode);

			vecVisited[iNextNode] = true;
		}
	}
}