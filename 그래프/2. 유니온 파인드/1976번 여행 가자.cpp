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

	int arrCities[201][201];
	vector<int>	vecTrip(iM);
	vector<int> vecNums(iN);

	for (int i = 0; i < iN; ++i)
	{
		for (int j = 0; j < iN; ++j)
		{
			cin >> arrCities[i][j];
		}
	}

	for (int i = 0; i < iM; ++i)
	{
		cin >> vecTrip[i];
		vecTrip[i]--;
	}

	for (int i = 0; i < iN; ++i)
	{
		vecNums[i] = i;
	}

	for (int i = 0; i < iN; ++i)
	{
		for (int j = 0; j < iN; ++j)
		{
			if (arrCities[i][j])
			{
				Union(vecNums, i, j);
			}
		}
	}

	int iFirstRep = FindRep(vecNums, vecTrip[0]);

	for (int i = 1; i < vecTrip.size(); ++i)
	{
		if (iFirstRep != FindRep(vecNums, vecTrip[i]))
		{
			cout << "NO\n";
			return 0;
		}
	}

	cout << "YES\n";
	return 0;
}

void Union(vector<int>& vecNums, int iNum1, int iNum2)
{
	iNum1 = FindRep(vecNums, iNum1);
	iNum2 = FindRep(vecNums, iNum2);

	if (iNum1 != iNum2)
		vecNums[iNum2] = iNum1;

}

int FindRep(vector<int>& vecNums, int iNum)
{
	if (iNum != vecNums[iNum])
	{
		return vecNums[iNum] = FindRep(vecNums, vecNums[iNum]);
	}

	else
		return vecNums[iNum];
}
