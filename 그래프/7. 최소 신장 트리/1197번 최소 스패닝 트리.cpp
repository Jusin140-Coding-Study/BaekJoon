#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

typedef tuple<int, int, int> Edge;

void	Union(vector<int>& vecUnionFind, int iA, int iB);
int		Find(vector<int>& vecUnionFind, int iA);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iV, iE;
	cin >> iV >> iE;

	priority_queue<Edge, vector<Edge>, greater<Edge>>	pqEdges;
	vector<int>		vecUnionFind(iV + 1);

	for (int i = 1; i <= iV; ++i)
	{
		vecUnionFind[i] = i;
	}

	int iA, iB, iC;

	for (int i = 0; i < iE; ++i)
	{
		cin >> iA >> iB >> iC;

		pqEdges.push(make_tuple(iC, iA, iB));
	}

	Edge eCurEdge;
	int iNode1, iNode2, iWeight;

	int iResult = 0;
	int iEdgeCnt = 0;

	while (iEdgeCnt < iV - 1)
	{
		eCurEdge = pqEdges.top();
		pqEdges.pop();

		iNode1 = get<1>(eCurEdge);
		iNode2 = get<2>(eCurEdge);
		iWeight = get<0>(eCurEdge);

		// 사이클이 생성되지 않는 에지라면
		if (Find(vecUnionFind, iNode1) != Find(vecUnionFind, iNode2))
		{
			Union(vecUnionFind, iNode1, iNode2);
			iResult += iWeight;
			iEdgeCnt++;
		}
	}

	cout << iResult;

	return 0;
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
