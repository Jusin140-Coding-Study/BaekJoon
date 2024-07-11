#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iNumMaterial = 0, iResult = 0;
	int iCnt = 0;

	cin >> iNumMaterial;
	cin >> iResult;

	vector<int> iMaterials(iNumMaterial);

	for (int i = 0; i < iNumMaterial; ++i)
	{
		cin >> iMaterials[i];
	}

	int iStartIdx = 0, iEndIdx = iNumMaterial - 1;

	sort(iMaterials.begin(), iMaterials.end());

	while (iStartIdx < iEndIdx)
	{
		if (iMaterials[iStartIdx] + iMaterials[iEndIdx] == iResult)
		{
			iCnt++;
			iStartIdx++;
			iEndIdx--;
		}
		else if (iMaterials[iStartIdx] + iMaterials[iEndIdx] > iResult)
		{
			iEndIdx--;
		}
		else
		{
			iStartIdx++;
		}
	}

	cout << iCnt << "\n";
}