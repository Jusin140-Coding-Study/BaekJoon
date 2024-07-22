#include <iostream>
#include <vector>
using namespace std;

int GCD(int iNum1, int iNum2, vector<int>& vecQuotient)
{
	if (iNum2 == 0)
		return iNum1;

	vecQuotient.push_back(iNum1 / iNum2);
	
	return GCD(iNum2, iNum1 % iNum2, vecQuotient);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iA, iB, iC;
	cin >> iA >> iB >> iC;

	vector<int> vecQuotient;

	int iGCD = GCD(iA, iB, vecQuotient);

	if (iC % iGCD != 0)
	{
		cout << -1;
		return 0;
	}

	int iXPrev = 1, iYPrev = 0;
	int iX, iY;

	for (int i = vecQuotient.size() - 1; i >= 0; --i)
	{
		iX = iYPrev;
		iY = iXPrev - iYPrev * vecQuotient[i];

		iXPrev = iX;
		iYPrev = iY;
	}

	cout << iX * (iC / iGCD) << ' ' << iY * (iC / iGCD);

	return 0;
}