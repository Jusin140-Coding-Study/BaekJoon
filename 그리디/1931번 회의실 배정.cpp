#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	int iCnt = 0;

	int iEnd = 0;

	vector<pair<int, int>> vecInput(iN);

	for (int i = 0; i < iN; ++i)
	{
		cin >> vecInput[i].second >> vecInput[i].first;
	}
	
	sort(vecInput.begin(), vecInput.end());

	for (int i = 0; i < iN; ++i)
	{
		if (vecInput[i].second >= iEnd)
		{
			iEnd = vecInput[i].first;
			iCnt++;
		}
	}

	cout << iCnt;
}