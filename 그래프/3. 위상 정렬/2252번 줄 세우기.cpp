#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM;

	cin >> iN >> iM;

	vector<vector<int>> vecStudent(iN);
	vector<int> vecInDegree(iN, 0);
	queue<int>	qStudent;
	vector<int> vecSorted(iN);

	int iStud1, iStud2;

	for (int i = 0; i < iM; ++i)
	{
		cin >> iStud1 >> iStud2;

		vecStudent[iStud1 - 1].push_back(iStud2 - 1);
		vecInDegree[iStud2 - 1]++;
	}

	int iIdx = 0;

	for (int i = 0; i < iN; ++i)
	{
		if (0 == vecInDegree[i])
		{
			qStudent.push(i);
		}
	}

	int iCur, iNext;

	while (!qStudent.empty())
	{
		int iCur = qStudent.front();

		vecSorted[iIdx++] = iCur + 1;
		qStudent.pop();

		cout << iCur + 1 << ' ';

		for (int i = 0; i < vecStudent[iCur].size(); ++i)
		{
			iNext = vecStudent[iCur][i];

			vecInDegree[iNext]--;

			if (0 == vecInDegree[iNext])
			{
				qStudent.push(iNext);
			}
		}
	}
}