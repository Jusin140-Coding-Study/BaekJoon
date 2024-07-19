/*
* @title    : 1541번 잃어버린 괄호(실버2)
* @content  : 그리디
* @author   : 손동찬
* @date     : 240715
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

	string strEquation;
	cin >> strEquation;

	int iResult = 0;
	string strParts = "";
	int iParts = 0;
	int iAdd = 1;
	
	for (int i = 0; i < strEquation.size(); ++i)
	{
		if (isdigit(strEquation[i]))
			strParts += strEquation[i];
		else
		{
			if (strEquation[i] == '-')
			{
				iParts += (iAdd * stoi(strParts));
				iResult += iParts;

				strParts = "";
				iParts = 0;
				iAdd = -1;
			}
			else
			{
				if (iAdd)
				{
					iResult += (iAdd * stoi(strParts));
					strParts = "";
				}
				else
				{
					iParts += (iAdd * stoi(strParts));
					strParts = "";
				}
			}
		}
	}

	iParts += (iAdd * stoi(strParts));
	iResult += iParts;
	strParts = "";

	cout << iResult;

	return 0;
}
