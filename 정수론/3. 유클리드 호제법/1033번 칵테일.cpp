#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

long long GCD(long long lNum1, long long lNum2)
{
	return (0 == lNum2) ? lNum1 : GCD(lNum2, lNum1 % lNum2);
}

void DFS(vector<vector<tuple<int, int, int>>>& vecInput, vector<bool>& vecVisited, vector<long>& vecNodes, int iCurNode);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	vector<vector<tuple<int, int, int>>>	vecInput(iN);
	vector<bool>							vecVisited(iN, false);
	vector<long>							vecNodes(iN, 0);

	int iA, iB, iP, iQ;
	long lLCM = 1;

	for (int i = 0; i < iN - 1; ++i)
	{
		cin >> iA >> iB >> iP >> iQ;

		vecInput[iA].push_back(make_tuple(iB, iP, iQ));
		vecInput[iB].push_back(make_tuple(iA, iQ, iP));

		lLCM *= (iP * iQ / GCD(iP, iQ));
	}

	vecNodes[0] = lLCM;
	DFS(vecInput, vecVisited, vecNodes, 0);
	long long lGCD = vecNodes[0];

	for (int i = 1; i < iN; ++i)
		lGCD = GCD(lGCD, vecNodes[i]);

	for (int i = 0; i < iN; ++i)
		cout << vecNodes[i] / lGCD << ' ';

	return 0;
}

void DFS(vector<vector<tuple<int, int, int>>>& vecInput, vector<bool>& vecVisited, vector<long>& vecNodes, int iCurNode)
{
	vecVisited[iCurNode] = true;

	int iNextNode;

	for (tuple<int, int, int> i : vecInput[iCurNode])
	{
		iNextNode = get<0>(i);
		if (!vecVisited[iNextNode])
		{
			vecNodes[iNextNode] = vecNodes[iCurNode] * get<2>(i) / get<1>(i);
			DFS(vecInput, vecVisited, vecNodes, iNextNode);
		}
	}
}