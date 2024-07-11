#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iSize, iTimes;

	cin >> iSize >> iTimes;

	vector<vector<int>> iSum(iSize + 1, vector<int>(iSize + 1, 0));

	for (int i = 1; i <= iSize; ++i)
	{
		for (int j = 1; j <= iSize; ++j)
		{
			int iNum;

			cin >> iNum;

			iSum[i][j] = iSum[i - 1][j] + iSum[i][j - 1] - iSum[i - 1][j - 1] + iNum;
		}
	}

	for (int i = 0; i < iTimes; ++i)
	{
		int iX1, iY1, iX2, iY2;

		cin >> iX1 >> iY1 >> iX2 >> iY2;

		cout << iSum[iX2][iY2] - iSum[iX1 - 1][iY2] - iSum[iX2][iY1 - 1] + iSum[iX1 - 1][iY1 - 1] << "\n";
	}
}