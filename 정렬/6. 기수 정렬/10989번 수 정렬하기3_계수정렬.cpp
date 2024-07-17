#include <iostream>
#include <vector>
#include <queue>
using namespace std;


void RadixSort(vector<int>& vecNums, vector<int>& vecSort,
	queue<int> qNums[10], int iCnt);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	vector<int> vecNums(iN, 0);
	vector<int> vecSort(iN, 0);

	for (int i = 0; i < iN; ++i)
		cin >> vecNums[i];

	queue<int> qNums[10];

	RadixSort(vecNums, vecSort, qNums, 1);

	for (int i = 0; i < iN; ++i)
	{
		cout << vecNums[i] << '\n';
	}
}

void RadixSort(vector<int>& vecNums, vector<int>& vecSort,
	queue<int> qNums[10], int iCnt)
{
	if (iCnt >= 10000)
		return;

	for (int i = 0; i < vecNums.size(); ++i)
	{
		vecSort[i] = vecNums[i];
	}

	for (int i = 0; i < vecNums.size(); ++i)
	{
		qNums[(vecSort[i] / iCnt) % 10].push(vecSort[i]);
	}

	int iVecIdx = 0;
	int iQueueIdx = 0;

	while (true)
	{
		while(qNums[iQueueIdx].empty())
			iQueueIdx++;

		if (iQueueIdx > 9)
			break;

		vecNums[iVecIdx++] = qNums[iQueueIdx].front();
		qNums[iQueueIdx].pop();
	}

	iCnt *= 10;

	RadixSort(vecNums, vecSort, qNums, iCnt);
}