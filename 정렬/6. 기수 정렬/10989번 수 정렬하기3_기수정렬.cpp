#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	short count[10001] = { 0 };
	short iInput = 0;

	for (int i = 0; i < iN; ++i)
	{
		cin >> iInput;

		count[iInput]++;
	}

	for (short i = 0; i <= 10000; ++i)
	{
		if (count[i] > 0)
		{
			for (short j = 0; j < count[i]; ++j)
				cout << i << '\n';
		}
	}
}