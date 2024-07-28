#include <iostream>
#include <vector>
using namespace std;

void DFS(vector<vector<int>>& vecNode, vector<bool>& vecVisited, int iCurNode, int iRemove, int& iLeafCnt);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	vector<vector<int>> vecNode(iN);

	int iParent, iRoot;

	for (int i = 0; i < iN; ++i)
	{
		cin >> iParent;

		if (iParent != -1)
		{
			vecNode[iParent].push_back(i);
		}

		else
			iRoot = i;
	}

	int iRemove;
	cin >> iRemove;

	if (iRemove == iRoot)
	{
		cout << 0;
		return 0;
	}

	vector<bool> vecVisited(iN, false);

	int iLeafCnt = 0;

	DFS(vecNode, vecVisited, iRoot, iRemove, iLeafCnt);

	cout << iLeafCnt;
}

void DFS(vector<vector<int>>& vecNode, vector<bool>& vecVisited, int iCurNode, int iRemove, int& iLeafCnt)
{
	int iChildCnt = 0;

	for (int iChild : vecNode[iCurNode])
	{
		if (!vecVisited[iChild] && iChild != iRemove)
		{
			vecVisited[iChild] = true;
			DFS(vecNode, vecVisited, iChild, iRemove, iLeafCnt);
			iChildCnt++;
		}
	}

	if (0 == iChildCnt)
		iLeafCnt++;
}