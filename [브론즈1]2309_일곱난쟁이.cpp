#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> vecPeople = vector<int>(9, 0);
	vector<int> vecLie;
	int iSum = 0;
	int iResult = 0;
	bool bCompleted = false;

	for (int i = 0; i < 9; ++i)
	{
		cin >> vecPeople[i];
		iSum += vecPeople[i];
	}

	for (int i = 0; i < 9; ++i)
	{
		for (int j = i; j < 9; ++j)
		{
			if (100 == iSum - (vecPeople[i] + vecPeople[j]) && i != j)
			{
				vecLie.push_back(vecPeople[i]);
				vecLie.push_back(vecPeople[j]);
				bCompleted = true;
				break;
			}
		}
		if (bCompleted)
			break;
	}

	sort(vecPeople.begin(), vecPeople.end());

	for (const auto& iter : vecPeople)
	{
		if (vecLie[0] != iter && vecLie[1] != iter)
			cout << iter << "\n";
	}

	return 0;
}