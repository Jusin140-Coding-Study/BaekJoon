/*
* @title    : 2342�� Dance Dance Revolution(���3)
* @content  : ���� ��ȹ��
* @author   : �յ���
* @date     : 240809
* @time     : 60 ms
* @memory   : 32612 KB
* @state    : �Ϸ�
*/
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	vector<vector<vector<int>>> DP(100001, vector<vector<int>>(5, vector<int>(5, 400001)));
	DP[0][0][0] = 0;

	int iInput ;
	cin >> iInput;
	int iCount = 0;

	while (iInput != 0)
	{
		++iCount;
		for (int i = 0; i <= 4; ++i)
		{
			int iMin = DP[iCount - 1][i][0] + 2;
			for (int j = 1; j <= 4; ++j)
			{
				if (i == j) continue;

				if (abs(iInput - j) == 2)
					iMin = min(iMin, DP[iCount - 1][i][j] + 4);
				else if(abs(iInput - j) == 0)
					iMin = min(iMin, DP[iCount - 1][i][j] + 1);
				else
					iMin = min(iMin, DP[iCount - 1][i][j] + 3);
			}
			DP[iCount][i][iInput] = iMin;
		}
		for (int i = 0; i <= 4; ++i)
		{
			int iMin = DP[iCount - 1][0][i] + 2;
			for (int j = 1; j <= 4; ++j)
			{
				if (i == j) continue;

				if (abs(iInput - j) == 2)
					iMin = min(iMin, DP[iCount - 1][j][i] + 4);
				else if (abs(iInput - j) == 0)
					iMin = min(iMin, DP[iCount - 1][j][i] + 1);
				else
					iMin = min(iMin, DP[iCount - 1][j][i] + 3);
			}
			DP[iCount][iInput][i] = iMin;
		}

		cin >> iInput;
	}

	int Result = 400001;
	for (int i = 0; i <= 4; ++i)
		for (int j = 0; j <= 4; ++j)
			Result = min(Result, DP[iCount][i][j]);
	
	cout << Result;

	return 0;
}