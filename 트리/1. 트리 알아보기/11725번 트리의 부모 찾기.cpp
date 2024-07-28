#include <iostream>
#include <vector>
using namespace std;

void DFS(vector<vector<int>>& vecNodes, vector<bool>& vecVisited, int iNode, vector<int>& vecParent);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	int iNode1, iNode2;

	vector<vector<int>> vecNodes(iN + 1);
	vector<bool>		vecVisited(iN + 1, false);

	for (int i = 0; i < iN - 1; ++i)
	{
		cin >> iNode1 >> iNode2;
		vecNodes[iNode1].push_back(iNode2);
		vecNodes[iNode2].push_back(iNode1);
	}

	vector<int> vecParent(iN +1);

	DFS(vecNodes, vecVisited, 1, vecParent);

	for (int i = 2; i <= iN; ++i)
	{
		cout << vecParent[i] << '\n';
	}
}

void DFS(vector<vector<int>>& vecNodes, vector<bool>& vecVisited, int iNode, vector<int>& vecParent)
{
	for (int iNextNode : vecNodes[iNode])
	{
		if (!vecVisited[iNextNode])
		{
			vecVisited[iNextNode] = true;
			vecParent[iNextNode] = iNode;
			DFS(vecNodes, vecVisited, iNextNode, vecParent);
		}
	}
}