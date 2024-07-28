#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

typedef tuple<int, int, int> Edge;

void Union(vector<int>& vecUnionFind, int iA, int iB);
int Find(vector<int>& vecUnionFind, int iA);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	int iSum = 0;

	char chInput;
	int iInput;

	priority_queue<Edge, vector<Edge>, greater<Edge>> pqEdges;

	for (int i = 0; i < iN; ++i)
	{
		for (int j = 0; j < iN; ++j)
		{
			cin >> chInput;
			if ('0' == chInput)
				iInput = 0;

			else
				iInput = chInput >= 97 ? chInput - 'a' + 1 : chInput - 'A' + 27;

			if (i != j && iInput != 0)
				pqEdges.push(Edge(iInput, i, j));

			iSum += iInput;
		}
	}

	vector<int> vecUnionFind(iN);

	for (int i = 0; i < iN; ++i)
	{
		vecUnionFind[i] = i;
	}

	int iResult = 0;
	int iEdgeCnt = 0;

	Edge eCurEdge;
	int iCom1, iCom2, iWeight;

	while (!pqEdges.empty())
	{
		eCurEdge = pqEdges.top();
		pqEdges.pop();

		iCom1 = get<1>(eCurEdge);
		iCom2 = get<2>(eCurEdge);
		iWeight = get<0>(eCurEdge);

		if (Find(vecUnionFind, iCom1) != Find(vecUnionFind, iCom2))
		{
			Union(vecUnionFind, iCom1, iCom2);
			iResult += iWeight;
			iEdgeCnt++;
		}
	}

	if (iN - 1 == iEdgeCnt)
		cout << iSum - iResult;

	else
		cout << -1;

	return 0;
}

void Union(vector<int>& vecUnionFind, int iA, int iB)
{
	iA = Find(vecUnionFind, iA);
	iB = Find(vecUnionFind, iB);

	if (iA != iB)
		vecUnionFind[iB] = iA;
}

int Find(vector<int>& vecUnionFind, int iA)
{
	if (iA == vecUnionFind[iA])
		return iA;

	return vecUnionFind[iA] = Find(vecUnionFind, vecUnionFind[iA]);
}