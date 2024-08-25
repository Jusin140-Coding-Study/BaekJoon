#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Output(const vector<int>& _vecNums, int iIndex);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iInput = 1;

	while (true)
	{
		cin >> iInput;
		if (0 == iInput) break;

		vector<int> vecNums = vector<int>(iInput, -1);

		for (int i = 0; i < iInput; ++i)
			cin >> vecNums[i];

		for (int i = 0; i < iInput; ++i)
		{
			for (int j = i + 1; j < iInput; ++j)
			{
				for (int k = j + 1; k < iInput; ++k)
				{
					for (int l = k + 1; l < iInput; ++l)
					{
						for (int o = l + 1; o < iInput; ++o)
						{
							for (int p = o + 1; p < iInput; ++p)
							{
								Output(vecNums, i);
								Output(vecNums, j);
								Output(vecNums, k);
								Output(vecNums, l);
								Output(vecNums, o);
								Output(vecNums, p);
								cout << "\n";
							}
						}
					}
				}
			}
		}

		cout << "\n";
	}

	return 0;
}

void Output(const vector<int>& _vecNums, int iIndex)
{
	if (-1 != _vecNums[iIndex])
		cout << _vecNums[iIndex] << " ";
}