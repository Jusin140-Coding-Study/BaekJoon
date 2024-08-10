/*
* @title    : 1915�� ���� ū ���簢��(���4)
* @content  : ���� ��ȹ��
* @author   : �յ���
* @date     : 240809
* @time     : 8 ms
* @memory   : 6000 KB
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
	
	int N, M;
	cin >> N >> M;
	vector<vector<int>> DP(N + 1, vector<int>(M + 1 , 0));
	for (int i = 1; i <= N; ++i)
	{
		string strNum;
		cin >> strNum;

		for (int j = 1; j <= M; ++j)
			DP[i][j] = strNum[j-1] - '0';
	}

	int iMax = 0;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			if (DP[i][j] && DP[i - 1][j - 1] && DP[i][j - 1] && DP[i - 1][j])
			{
				DP[i][j] = DP[i - 1][j - 1];
				DP[i][j] = min(DP[i][j], DP[i][j - 1]);
				DP[i][j] = min(DP[i][j], DP[i - 1][j]);
				DP[i][j] += 1;
			}
			iMax = max(iMax, DP[i][j]);
		}
	}
	
	cout << iMax * iMax;

	return 0;
}