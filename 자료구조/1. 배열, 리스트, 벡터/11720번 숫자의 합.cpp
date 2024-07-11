#include <iostream>
#include <string>
using namespace std;

int main()
{
	int iCnt = 0;

	cin >> iCnt;

	string strNum = "";

	cin >> strNum;

	int iSum = 0;

	for (int i = 0; i < strNum.length(); ++i)
	{
		iSum += strNum[i] - 48;
	}

	cout << iSum << endl;
}