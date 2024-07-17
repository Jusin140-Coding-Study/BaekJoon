#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	vector<bool> vecPrime(1003002, true);

	string strPalindrome;
	int iFront = 0;
	int iBack = 0;
	bool	isPalindrome = false;

	for (int i = 2; i < vecPrime.size(); ++i)
	{
		if (!vecPrime[i])
			continue;

		for (int j = 2; ; ++j)
		{
			if (i * j >= vecPrime.size())
				break;

			vecPrime[i * j] = false;
		}

		if (i >= iN)
		{
			isPalindrome = false;

			strPalindrome = to_string(i);

			iFront = 0;
			iBack = strPalindrome.length() - 1;

			while (iFront <= iBack)
			{
				if (strPalindrome[iFront] == strPalindrome[iBack])
				{
					iFront++;
					iBack--;
					isPalindrome = true;
				}
				else
				{
					isPalindrome = false;
					break;
				}
			}

			if (isPalindrome)
			{
				cout << i;
				break;
			}
		}
	}
}