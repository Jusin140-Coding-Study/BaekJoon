#include <iostream>
#include <vector>
using namespace std;

void TestCase();
bool DFS(vector<vector<int>>& vecNodes, vector<bool>& vecVisited, vector<int>& vecSplit, int iCurNode);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iK;
	cin >> iK;

	for (int i = 0; i < iK; ++i)
	{
		TestCase();
	}
}

void TestCase()
{
	int iV, iE;
	cin >> iV >> iE;

	vector<vector<int>> vecNodes(iV + 1);
	vector<bool>		vecVisited(iV + 1, false);
	vector<int>			vecSplit(iV + 1);

	int iNode1, iNode2;

	for (int i = 0; i < iE; ++i)
	{
		cin >> iNode1 >> iNode2;

		vecNodes[iNode1].push_back(iNode2);
		vecNodes[iNode2].push_back(iNode1);
	}

	bool bResult = false;

	for (int i = 1; i <= iV; ++i)
	{
		if (!DFS(vecNodes, vecVisited, vecSplit, i))
		{
			cout << "NO\n";
			return;
		}
	}

	cout << "YES\n";
}

bool DFS(vector<vector<int>>& vecNodes, vector<bool>& vecVisited, vector<int>& vecSplit, int iCurNode)
{
	int iNextNode;

	for (int i = 0; i < vecNodes[iCurNode].size(); ++i)
	{
		iNextNode = vecNodes[iCurNode][i];

		if (vecVisited[iNextNode])
		{
			if (vecSplit[iNextNode] == vecSplit[iCurNode])
				return false;

			continue;
		}

		vecVisited[iNextNode] = true;
		vecSplit[iNextNode] = (vecSplit[iCurNode]) + 1 % 2;

		return DFS(vecNodes, vecVisited, vecSplit, iNextNode);
	}

	return true;
}