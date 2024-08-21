/*
* @title    : 9184번 신나는 함수 실행(실버2)
* @content  : 동적 계획법 1
* @author   : 손동찬
* @date     : 240813
* @time     : 4 ms
* @memory   : 2020 KB
* @state    : 완료
*/
#include <iostream>

using namespace std;


void WriteText(int _A, int _B, int _C, int Result)
{
	cout << "w(" << _A << ", " << _B << ", " << _C << ") = " << Result << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int DP[21][21][21];

	for (int i = 0; i <= 20; ++i)
		for (int j = 0; j <= 20; ++j)
			for (int k = 0; k <= 20; ++k)
			{
				if (i == 0 || j == 0 || k == 0)
					DP[i][j][k] = 1;
				else if (i < j && j < k)
					DP[i][j][k] = DP[i][j][k - 1] + DP[i][j - 1][k - 1] - DP[i][j - 1][k];
				else
					DP[i][j][k] = DP[i - 1][j][k] + DP[i - 1][j - 1][k] + DP[i - 1][j][k - 1] - DP[i - 1][j - 1][k - 1];
			}

	int a, b, c;

	while (1)
	{
		cin >> a >> b >> c;

		if (a == -1 && b == -1 && c == -1)
			break;

		if (a <= 0 || b <= 0 || c <= 0)
			WriteText(a, b, c, 1);
		else if(a >20 || b>20 ||c >20)
			WriteText(a, b, c, DP[20][20][20]);
		else 
			WriteText(a, b, c, DP[a][b][c]);
	}

	return 0;
}
