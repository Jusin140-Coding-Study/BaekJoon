/*
* @title    : 1516번 게임 개발(골드3)
* @content  : 위상 정렬
* @author   : 손동찬
* @date     : 240721
* @time     : 4 ms
* @memory   : 2424 KB
* @state    : 완료
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<int> vecTimes(N + 1);
	vector<vector<int>> vecTechTree(N + 1);

	vector<int> vecTotalTimes(N + 1, 0);
	vector<int> vecTechCount(N + 1);

	for (int i = 1; i <= N; ++i)
	{
		cin >> vecTimes[i];
		int iNum;
		cin >> iNum;
		while (iNum != -1)
		{
			vecTechTree[iNum].push_back(i);
			++vecTechCount[i];
			cin >> iNum;
		}
	}

	queue<int> queNums;
	for (int i = 1; i <= N; ++i)
		if (!vecTechCount[i])
			queNums.push(i);

	while (!queNums.empty())
	{
		int iNum = queNums.front();
		queNums.pop();
		vecTotalTimes[iNum] += vecTimes[iNum];

		for (int i = 0; i < vecTechTree[iNum].size(); ++i)
		{
			--vecTechCount[vecTechTree[iNum][i]];

			if (vecTotalTimes[vecTechTree[iNum][i]] < vecTotalTimes[iNum])
				vecTotalTimes[vecTechTree[iNum][i]] = vecTotalTimes[iNum];

			if (!vecTechCount[vecTechTree[iNum][i]])
			{
				queNums.push(vecTechTree[iNum][i]);
				continue;
			}

		}
	}

	for (int i = 1; i <= N; ++i)
		cout << vecTotalTimes[i] << "\n";

	return 0;
}
