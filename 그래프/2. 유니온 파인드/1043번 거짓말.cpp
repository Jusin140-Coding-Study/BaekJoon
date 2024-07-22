#include <iostream>
#include <vector>
using namespace std;

void Union(vector<int>& vecNums, int iNum1, int iNum2);
int FindRep(vector<int>& vecNums, int iNum);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM;

	cin >> iN >> iM;

	vector<int>			vecNums(iN);
	vector<int>			vecTruth;
	vector<vector<int>> vecParties(iM);

	for (int i = 0; i < iN; ++i)
		vecNums[i] = i;

	int iTruthCnt = 0;
	cin >> iTruthCnt;

	int iTruthNum = 0;

	for (int i = 0; i < iTruthCnt; ++i)
	{
		cin >> iTruthNum;
		vecTruth.push_back(iTruthNum - 1);
	}

	int iAttendeesCnt = 0;
	int iAttendeesNum = 0;

	bool canLie = true;
	int	iLieCnt = 0;

	for (int i = 0; i < iM; ++i)
	{
		cin >> iAttendeesCnt;

		for (int j = 0; j < iAttendeesCnt; ++j)
		{
			cin >> iAttendeesNum;
			vecParties[i].push_back(iAttendeesNum - 1);

			if (j >= 1)
				Union(vecNums, vecParties[i][j], vecParties[i][j - 1]);
		}
	}

	for (int i = 0; i < iM; ++i)
	{
		canLie = true;

		int iPartyRep = vecParties[i][0];

		for (int j = 0; j < vecTruth.size(); ++j)
		{
			if (FindRep(vecNums, iPartyRep) == FindRep(vecNums, vecTruth[j]))
			{
				canLie = false;
				break;
			}
		}

		if (canLie)
			iLieCnt++;
	}

	cout << iLieCnt;

	return 0;
}

void Union(vector<int>& vecNums, int iNum1, int iNum2)
{
	iNum1 = FindRep(vecNums, iNum1);
	iNum2 = FindRep(vecNums, iNum2);

	if (iNum1 != iNum2)
	{
		vecNums[iNum2] = iNum1;
	}
}

int FindRep(vector<int>& vecNums, int iNum)
{
	if (iNum == vecNums[iNum])
		return iNum;

	else
		return vecNums[iNum] = FindRep(vecNums, vecNums[iNum]);
}