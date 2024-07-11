#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iSize = 0;
	cin >> iSize;

	int iResult = 0;

	vector<int> vecNums(iSize, 0);

	for (int i = 0; i < iSize; ++i)
	{
		cin >> vecNums[i];
	}

	sort(vecNums.begin(), vecNums.end());

	for (int i = 0; i < iSize; ++i)
	{
		int iTarget = vecNums[i];

		int iFrontIdx = 0, iBackIdx = iSize - 1;

		while (iFrontIdx < iBackIdx)
		{
			if (vecNums[iFrontIdx] + vecNums[iBackIdx] == iTarget)
			{
				if (iFrontIdx != i && iBackIdx != i)
				{
					iResult++;
					break;
				}
				else if (iFrontIdx == i)
				{
					iFrontIdx++;
				}
				else if (iBackIdx == i)
					iBackIdx--;
			}
			else if (vecNums[iFrontIdx] + vecNums[iBackIdx] < iTarget)
				iFrontIdx++;

			else
				iBackIdx--;
		}
	}

	cout << iResult << "\n";
}