#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iCnt = 0;
	int iTimes = 0;

	cin >> iCnt;
	cin >> iTimes;

	int iSum[100001];

	iSum[0] = 0;

	for (int i = 1; i <= iCnt; ++i)
	{
		int iNum;
		cin >> iNum;

		iSum[i] = iSum[i - 1] + iNum;
	}

	for (int i = 0; i < iTimes; ++i)
	{
		int iStart, iEnd;

		cin >> iStart;
		cin >> iEnd;

		cout << iSum[iEnd] - iSum[iStart - 1] << endl;
	}
}