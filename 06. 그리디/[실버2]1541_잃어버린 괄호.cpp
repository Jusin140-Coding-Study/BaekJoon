#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int Result = 0;
	int IsMinusAppear = false;
	string strExp = "";
	cin >> strExp;
	
	string strTemp = "";
	for (const auto& iter : strExp)
	{
		if (isdigit(iter))
		{
			strTemp += iter;

			// 마지막 숫자인 경우
			if (&iter == &*(strExp.end() - 1))
			{
				if (!IsMinusAppear)
				{
					Result += stoi(strTemp);
					strTemp = "";
				}
				else
				{
					Result -= stoi(strTemp);
					strTemp = "";
				}
			}
		}
		else
		{
			if (!IsMinusAppear)
			{
				if ('+' == iter)
				{
					Result += stoi(strTemp);
					strTemp = "";
				}
				else
				{
					Result += stoi(strTemp);
					strTemp = "";
					IsMinusAppear = true;
				}
			}
			else
			{
				Result -= stoi(strTemp);
				strTemp = "";
			}
		}
	}

	cout << Result;
}