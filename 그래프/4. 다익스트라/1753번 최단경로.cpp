#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iV, iE;

	cin >> iV >> iE;

	int iInf = iE * 10 + 1;

	typedef pair<int, int> edge;
	vector<vector<edge>>	vecNodes(iV + 1);
	vector<int>						vecDist(iV + 1, iInf);
	vector<bool>					vecVisited(iV + 1, false);
	priority_queue<edge, vector<edge>, greater<edge>>	pqDistNode;

	int iStart;

	cin >> iStart;

	vecDist[iStart] = 0;
	pqDistNode.push(make_pair(0, iStart));

	int iNode1, iNode2, iW;

	for (int i = 0; i < iE; ++i)
	{
		cin >> iNode1 >> iNode2 >> iW;

		vecNodes[iNode1].push_back(make_pair(iNode2, iW));
	}

	int iCurNode, iDist;

	while (!pqDistNode.empty())
	{
		iCurNode = pqDistNode.top().second;
		iDist = pqDistNode.top().first;
		pqDistNode.pop();

		if (vecVisited[iCurNode])
			continue;

		vecVisited[iCurNode] = true;

		for (pair<int, int> iNextNode : vecNodes[iCurNode])
		{
			if (vecDist[iNextNode.first] > vecDist[iCurNode] + iNextNode.second)
			{
				vecDist[iNextNode.first] = vecDist[iCurNode] + iNextNode.second;
				pqDistNode.push(make_pair(vecDist[iNextNode.first], iNextNode.first));
			}
		}
	}

	for (int i = 1; i <= iV; ++i)
	{
		if (vecDist[i] >= iInf)
			cout << "INF\n";

		else
			cout << vecDist[i] << '\n';
	}
}