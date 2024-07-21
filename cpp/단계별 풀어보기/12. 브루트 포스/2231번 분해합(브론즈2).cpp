/*
* @title    : 2231�� ������(�����2)
* @content  : ���Ʈ ����
* @author   : �յ���
* @date     : 240710
* @time     : 0ms
* @memory   : 2024 KB
* @state    : �Ϸ�
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