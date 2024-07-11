#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
	int iN = 0;
	cin >> iN;

	vector<int> vecInput(iN, 0);
	stack<int> stkIdx;
	vector<int> vecResult(iN, 0);


	for (int i = 0; i < iN; ++i)
		cin >> vecInput[i];

	stkIdx.push(0);

	for (int i = 1; i < iN; ++i)
	{
		while (stkIdx.size() && vecInput[stkIdx.top()] < vecInput[i])
		{
			vecResult[stkIdx.top()] = vecInput[i];
			stkIdx.pop();
		}

		stkIdx.push(i);
	}

	while (stkIdx.size())
	{
		vecResult[stkIdx.top()] = -1;
		stkIdx.pop();
	}

	for (int i = 0; i < iN; ++i)
		cout << vecResult[i] << " ";
}