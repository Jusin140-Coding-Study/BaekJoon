#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long iN;
	cin >> iN;

	long iResult = iN;

	for (int i = 2; i * i <= iN; ++i)
	{
		if (0 == iN % i)
		{
			iResult -= iResult / i;

			while (0 == iN % i)
				iN /= i;
		}
	}

	if (1 < iN)
	{
		iResult -= iResult / iN;
	}

	cout << iResult;
}