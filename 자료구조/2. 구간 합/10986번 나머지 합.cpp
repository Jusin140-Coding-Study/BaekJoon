#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM;
	cin >> iN >> iM;

	int iResult = 0;

	vector<long long> vecSum(iN, 0);
	vector<long long> vecRemainder(iM, 0);

	cin >> vecSum[0];

	for (int i = 1; i < iN; ++i)
	{
		int iInput = 0;
		cin >> iInput;

		vecSum[i] = vecSum[i - 1] + iInput;
	}

	for (int i = 0; i < iN; ++i)
	{
		int iRemainder = vecSum[i] % iM;

		if (iRemainder == 0)
			iResult++;

		vecRemainder[iRemainder]++;
	}

	for (int i = 0; i < iM; ++i)
	{
		if (vecRemainder[i] > 1)
			iResult = iResult + (vecRemainder[i] * (vecRemainder[i] - 1) / 2);
	}

	cout << iResult << "\n";
}