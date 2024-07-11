#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int iCnt = 0;

	cin >> iCnt;

	int iNum = 0;

	vector<int> vecNum;
	vecNum.reserve(iCnt);

	int iMax = 0;

	for (int i = 0; i < iCnt; ++i)
	{
		cin >> iNum;
		vecNum.push_back(iNum);

		if (iMax < iNum)
			iMax = iNum;
	}

	float fAvg = 0.0f;

	for (int i = 0; i < iCnt; ++i)
	{
		fAvg += (float)vecNum[i] / (float)iMax;
	}

	cout << fAvg / iCnt * 100.f << endl;
}