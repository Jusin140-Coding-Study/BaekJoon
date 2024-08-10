/*
* @title    : 9252번 LCS 2 (골드4)
* @content  : 동적 계획법
* @author   : 손동찬
* @date     : 240809
* @time     : 4ms
* @memory   : 6004 KB
* @state    : 완료
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string str_1, str_2;
	cin >> str_1 >> str_2;
	int iLength_1 = str_1.size();
	int iLength_2 = str_2.size();

	vector<vector<int>> DP(iLength_1 + 1, vector<int>(iLength_2 + 1, 0));

	for (int i = 1; i <= iLength_1; ++i)
	{
		for (int j = 1; j <= iLength_2; ++j)
		{
			if (str_1[i-1] == str_2[j-1])
				DP[i][j] = DP[i - 1][j - 1] + 1;
			else
				DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
		}
	}

	int a = DP[iLength_1][iLength_2];
	cout << a <<"\n";

	string strResult = "";

	--iLength_1;
	--iLength_2;
	while (iLength_1 >= 0 && iLength_2 >= 0)
	{
		if (str_1[iLength_1] == str_2[iLength_2])
		{
			strResult += str_1[iLength_1];

			--iLength_1;
			--iLength_2;
		}
		else
		{
			if(DP[iLength_1][iLength_2+1] > DP[iLength_1+1][iLength_2])
				--iLength_1;
			else
				--iLength_2;
		}
	}

	for (int i = strResult.size() - 1; i >= 0; --i)
		cout << strResult[i];

	return 0;
}