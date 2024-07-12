/*
* @title    : 2231번 분해합(브론즈2)
* @content  : 브루트 포스
* @author   : 손동찬
* @date     : 240710
* @time     : 0ms
* @memory   : 2024 KB
* @state    : 완료
*/
#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string strNum;
	cin >> strNum;

	int iNumSize = strNum.size();
	int iNum = stoi(strNum);
	int iCur = iNum;
	int iResult = 0;

	while (iCur + (iNumSize * 10) >= iNum)
	{
		iCur--;
		string strA = to_string(iCur);
		int iSum = 0;
		for (int i = 0; i < strA.size(); ++i)
			iSum += strA[i] - '0';
		
		if (iCur + iSum == iNum)
			iResult = iCur;
	}
	cout << iResult;

	return 0;
}