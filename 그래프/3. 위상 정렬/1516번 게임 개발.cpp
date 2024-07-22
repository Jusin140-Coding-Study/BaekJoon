#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	vector<int> vecTimes(iN + 1, 0);
	vector<vector<int>> vecPreBuilt(iN + 1);
	vector<int>	vecInDegree(iN + 1, 0);
	vector<int> vecResult(iN + 1, 0);
	queue<int>	qBuildings;

	int iInput;

	for (int i = 1; i <= iN; ++i)
	{
		cin >> vecTimes[i];

		while (true)
		{
			cin >> iInput;

			if (-1 == iInput)
				break;

			vecInDegree[i]++;
			vecPreBuilt[iInput].push_back(i);
		}
	}

	int iTime = 0;

	for (int i = 1; i <= iN; ++i)
	{
		if (0 == vecInDegree[i])
		{
			qBuildings.push(i);
		}
	}

	int iCur;

	while (!qBuildings.empty())
	{
		iCur = qBuildings.front();
		qBuildings.pop();

		for (int iNext : vecPreBuilt[iCur])
		{
			vecInDegree[iNext]--;

			vecResult[iNext] = max(vecResult[iNext], vecResult[iCur] + vecTimes[iCur]);

			if (0 == vecInDegree[iNext])
				qBuildings.push(iNext);
		}
	}

	for (int i = 1; i <= iN; ++i)
	{
		cout << vecResult[i] + vecTimes[i] << '\n';
	}
}