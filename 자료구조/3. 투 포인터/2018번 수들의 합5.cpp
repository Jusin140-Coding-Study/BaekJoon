#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iNum;
	int iCnt = 1;
	
	cin >> iNum;

	int iStartIdx = 1 , iEndIdx = 1;
	int iSum = 1;

	while (iEndIdx != iNum)
	{
		if (iSum == iNum)
		{
			iEndIdx++;
			iCnt++;
			iSum += iEndIdx;
		}

		else if (iSum < iNum)
		{
			iEndIdx++;
			iSum += iEndIdx;
		}

		else
		{
			iSum -= iStartIdx;
			iStartIdx++;
		}
	}

	cout << iCnt << "\n";
}